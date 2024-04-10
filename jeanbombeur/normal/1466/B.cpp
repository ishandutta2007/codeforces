#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (400 * 1000);

int Val[MAX_VALEURS];
int Occ[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    for (int i = 0; i <= 2 * nbValeurs + 1; i ++)
    {
        Occ[i] = 0;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
    }
    int ans = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (Occ[Val[i]] ++ == 0)
        {
            ans ++;
        }
        else if (Occ[Val[i] + 1] ++ == 0)
        {
            ans ++;
        }
    }
    printf("%d\n", ans);
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