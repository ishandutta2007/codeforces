#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//    <|_|>

const int MAX_VALEURS = (300 * 1000);

int Val[MAX_VALEURS];

int Prix[MAX_VALEURS];

int nbValeurs, nbCadeaux;

void Read() {
    scanf("%d%d", &nbValeurs, &nbCadeaux);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        Val[i] --;
    }
    for (int i = 0; i < nbCadeaux; i ++)
    {
        scanf("%d", &Prix[i]);
    }
    long long sum = 0;
    sort(Val, Val + nbValeurs);
    for (int i = nbValeurs - 1; i >= 0; i --)
    {
        if (Val[i] < nbValeurs - i - 1)
        {
            sum += Prix[Val[i]];
        }
        else
        {
            sum += Prix[nbValeurs - i - 1];
        }
    }
    printf("%lld\n", sum);
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