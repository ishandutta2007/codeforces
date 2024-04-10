#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//   <|_|>

const int MAX_VALEURS = (100 * 1000);

pair <int, int> Val[MAX_VALEURS];
int Tour[MAX_VALEURS];

pair <int, int> Hauteurs[MAX_VALEURS];

int nbBlocs, nbTours, diff;

void Read() {
    scanf("%d%d%d", &nbBlocs, &nbTours, &diff);
    for (int i = 0; i < nbBlocs; i ++)
    {
        scanf("%d", &Val[i].first);
        Val[i].second = i;
    }
    sort(Val, Val + nbBlocs);
    for (int i = 0; i < nbTours; i ++)
    {
        Hauteurs[i].first = 0;
        Hauteurs[i].second = i;
    }
    for (int i = 0; i < nbBlocs; i += nbTours)
    {
        sort(Hauteurs, Hauteurs + nbTours);
        for (int j = i; j < min(i + nbTours, nbBlocs); j ++)
        {
            Tour[Val[j].second] = Hauteurs[j - i].second;
            Hauteurs[j - i].first += Val[j].first;
        }
    }
    printf("YES\n");
    for (int i = 0; i < nbBlocs; i ++)
    {
        printf("%d ", Tour[i] + 1);
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