#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_LONGUEUR = 100;

int Perm[MAX_LONGUEUR];

int nbTests, longueur;

void Read() {
    scanf("%d", &nbTests);
    for (int i = 0.; i < nbTests; i ++)
    {
        scanf("%d", &longueur);
        for (int j = 0; j < longueur; j ++)
        {
            scanf("%d", &Perm[j]);
        }
        for (int j = longueur - 1; j >= 0; j --)
        {
            printf("%d ", Perm[j]);
        }
        printf("\n");
    }
    return;
}

int main() {
    Read();
    return 0;
}