#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (300 * 1000 + 1);

int Val[MAX_VALEURS];

pair <int, int> Pile[MAX_VALEURS];
int fin = 0;
int PlusGrand[MAX_VALEURS];
int Possible[MAX_VALEURS];

int nbValeurs, dist;

void Read() {
    scanf("%d", &nbValeurs);
    for (int i = 0; i <= nbValeurs; i ++)
    {
        PlusGrand[i] = 0;
        Possible[i] = nbValeurs;
    }
    fin = 0;
    Pile[fin ++] = make_pair(-1, -1);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        while (fin > 0 && Pile[-- fin].first > Val[i])
        {
            PlusGrand[Pile[fin].first] = max(PlusGrand[Pile[fin].first], i - Pile[fin - 1].second - 1);
        }
        fin ++;
        Pile[fin ++] = make_pair(Val[i], i);
    }
    while (-- fin > 0)
    {
        PlusGrand[Pile[fin].first] = max(PlusGrand[Pile[fin].first], nbValeurs - Pile[fin - 1].second - 1);
    }
    Possible[nbValeurs] = PlusGrand[1];
    for (int i = nbValeurs - 1; i >= 1; i --)
    {
        Possible[i] = min(Possible[i + 1], PlusGrand[nbValeurs - i + 1]);
    }
    for (int i = 1; i <= nbValeurs; i ++)
    {
        if (Possible[i] >= i)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
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