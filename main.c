//Rodrigo Perez Solis
//A01411278
//This program will ask the user for any amount of numbers and then
//we will seek for the numbers that repeat in the ones he introduced
// to finally tell him the quantity of numbers repeated

#include <stdio.h>
#include <stdlib.h>

// The compare function for the qsort function.
int Compare (const void * a, const void * b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    // variables declaration
    int num;
    int duplicate = 0;
    int counts;

    printf("how many values would you like to enter?");
    scanf("%d", &num);

    // Array declaration
    int numbers[num];

    for(int i = 0; i < num; i++){
        printf("%d:", i+1);
        scanf("%d", &numbers[i]);
    }

    qsort(numbers, num, sizeof(int), Compare);
//we look for numbers that are repeated
    for(int i = 0; i < num; i+=counts+1){
        counts = 0;
        for(int j = i + 1; j < num; j++){
            if(numbers[i] == numbers[j]){
                counts++;
            }
        }
        if(counts > 0){
            duplicate++;
        }
    }
//Here we tell the user how many numbers are duplicated
    printf("this is the amount of numbers that are repeated: %d.", duplicate);

    return 0;
}