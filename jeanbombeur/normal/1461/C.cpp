#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbValeurs, nbOperations;

void Read() {
    scanf("%d%d\n", &nbValeurs, &nbOperations);
    int maximum = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        if (Val[i] != i + 1)
        {
            maximum = i + 1;
        }
    }
    double proba = 0.0;
    if (maximum == 0)
    {
        proba = 1.0;
    }
    for (int i = 0; i < nbOperations; i ++)
    {
        int rang;
        double prob;
        scanf("%d%lf", &rang, &prob);
        if (rang >= maximum)
        {
            proba = proba + prob - proba * prob;
        }
    }
    printf("%lf\n", proba);
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