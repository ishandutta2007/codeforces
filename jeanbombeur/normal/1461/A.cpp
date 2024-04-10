#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbValeurs, dmax;

void Read() {
    scanf("%d%d", &nbValeurs, &dmax);
    int C[3] = {'a', 'b', 'c'};
    for (int i = 0; i < nbValeurs; i ++)
    {
        printf("%c", C[i % 3]);
    }
    printf("\n");
    return;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}