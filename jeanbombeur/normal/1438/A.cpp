#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_VALEURS = (1000 * 1000);

int Val[MAX_VALEURS];

int nbTests;
int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    //int sum = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
    //    scanf("%d", &Val[i]);
        printf("1 ");
        
        
    }
    printf("\n");
    //printf("%d\n", sum);
    return;
}

void Solve() {
    return;
}

int main() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}