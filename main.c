#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int *array[4];

void CheckBin(int num);
void FromBinToDec(int num);
void PrintArray(int num);
int EnterBin(void);

int main(){
    int num=0;
    num = EnterBin();
    
    CheckBin(num);
    
    for(int i=0; i<num; i++)
        array[1][i] = array[2][i];
    
    FromBinToDec(num);
    
    PrintArray(num);
    
    return 0;
}

void CheckBin(int num){
    for(int i=0;i<num;i++){
        int k=0;
        while(array[1][i] != 0){
            if(array[1][i]%10 == 0 || array[1][i]%10 == 1 || array[1][i]%10 == -1){
                array[2][i] += array[1][i]%10 * pow(10,k); k++;
            }
            array[1][i]/=10;
        }
    }
}

void FromBinToDec(int num){
    for(int i=0;i<num;i++) {
        int j = 0, k = 0, flag_uns = 1;
        if(array[2][i] < 0) {
            flag_uns = 0;
            array[2][i]*=-1;
        }
        while(array[2][i] != 0) {
            if(array[2][i]%10 == 1) {
                array[3][i]+= pow(2,k);
                k++;
            } else if (array[2][i]%10 == 0) {
                k++;
            }
            array[2][i] /= 10;
            j++;
            
        }
        if(flag_uns == 0){
            array[3][i]*=-1;
        }
    }
}

void PrintArray(int num){
    for(int i=0;i<num;i++)
        printf("BIN: %ld\tto\tDEC: %ld\n",array[1][i], array[3][i]);
}

int EnterBin(){
    int num = 0;
    printf("Enter amount of numbers: ");
    scanf("%d", &num);
    
    for(int i=0; i<4; i++)
        array[i] = calloc(num, sizeof(long int));
    
    for(int i=0;i<num;i++) {
        printf("%d number: ",i+1);
        scanf("%lu", &array[0][i]);
        array[1][i] = array[0][i];
    }
    return num;
}
