#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (50);

int Val[MAX_VALEURS];
int Atteint[MAX_VALEURS];

int nbValeurs;

void Read() {
    for (int i = 0; i < MAX_VALEURS; i ++)
    {
        Atteint[i] = 0;
    }
    scanf("%d", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
    }
    int ans = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        for (int j = i + 1; j < nbValeurs; j ++)
        {
            if (Atteint[Val[j] - Val[i]] ++ == 0)
            {
                ans ++;
            }
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