#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//   <|_|>

const int MAX_VALEURS = (200 * 1000);

int Nb[MAX_VALEURS][2];

int nbChaussettes, nbGauches, nbDroites;

void Read() {
    scanf("%d%d%d", &nbChaussettes, &nbGauches, &nbDroites);
    for (int i = 0; i < nbChaussettes; i ++)
    {
        Nb[i][0] = 0;
        Nb[i][1] = 0;
    }
    for (int i = 0; i < nbChaussettes; i ++)
    {
        int a;
        scanf("%d", &a);
        if (i < nbGauches)
            Nb[-- a][0] ++;
        else
            Nb[-- a][1] ++;
    }
    int nbRestants[2] = {0, 0};
    int nbBonus[2] = {0, 0};
    for (int i = 0; i < nbChaussettes; i ++)
    {
        int d = min(Nb[i][0], Nb[i][1]);
        Nb[i][0] -= d;
        Nb[i][1] -= d;
        if (Nb[i][0] & 1)
        {
            nbRestants[0] ++;
            Nb[i][0] --;
        }
        if (Nb[i][1] & 1)
        {
            nbRestants[1] ++;
            Nb[i][1] --;
        }
        if (Nb[i][0] > 0)
        {
            nbBonus[0] += Nb[i][0];
        }
        if (Nb[i][1] > 0)
        {
            nbBonus[1] += Nb[i][1];
        }
    }
    int d = nbRestants[0] + nbBonus[0] - nbRestants[1] - nbBonus[1];
    if (d >= 0)
    {
        printf("%d\n", nbRestants[1] + nbBonus[1] + min(d, nbBonus[0]) / 2 + max(0, d - nbBonus[0]));
        return;
    }
    d *= -1;
    printf("%d\n", nbRestants[0] + nbBonus[0] + min(d, nbBonus[1]) / 2 + max(0, d - nbBonus[1]));
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