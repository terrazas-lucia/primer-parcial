#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "director.h"
#include "peliculas.h"
#define CANT_PELICULAS 1000

int main()
{
    Pelicula pelicula[CANT_PELICULAS];
    int opcion;
    int id;
    int indiceVacio;
    int bandera=0;
    int salir=0;
    cargarDatosVacio(pelicula,CANT_PELICULAS);
    do
    {
        system("cls");
        fflush(stdin);
        if(chequearIndice(pelicula,CANT_PELICULAS) == -1)
        {
            bandera = 1;
        }
        else
        {
            bandera = 0;
        }
        getEntero(&opcion,3,"1)Cargar peliculas:\n2)Modificar informacion de la pelicula:\n3)Baja de peliculas\n4)Mostrar lista de peliculas ordenada\n5)Salir\n","\nError\n",6,0);
        switch(opcion)
        {
                case 1:
                    if(indicesVacios(pelicula,CANT_PELICULAS,&indiceVacio)==0)
                    {
                        cargarIndice(pelicula,indiceVacio,CANT_PELICULAS);
                        break;
                    }
                    else
                    {
                        printf("\nNo hay indice.\n");
                    }
                    break;
                case 2:
                    if(bandera == 1)
                    {
                        if(getEntero(&id,2,"\nIngrese el ID a modificar: ", "Error", CANT_PELICULAS, -1) == 0)
                        {
                            if(id >=0)
                            {
                                modificarID(pelicula,id,CANT_PELICULAS);
                            }
                            else
                            {
                                printf("\nError, indice invalido.\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 3:
                    if(bandera == 1)
                    {
                        if(getEntero(&id,2,"\nIngrese el ID para borrar: ", "Error", CANT_EMPLEADOS, -1) == 0)
                        {
                            if(id >=0)
                            {
                                borrarPantallaPorID(empleados, id,CANT_EMPLEADOS);
                            }
                            else
                            {
                                printf("\nError, indice invalido.\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 4:
                    if(bandera == 1)
                    {
                        mostrarEmpleadosOrdenados(empleados, CANT_EMPLEADOS);
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 5:
                    if(bandera == 1)
                    {
                        calcularTotalPromedioSalarios(empleados, CANT_EMPLEADOS);
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 6:
                salir = 1;
        }
    }while(salir==0);
    return 0;
}
