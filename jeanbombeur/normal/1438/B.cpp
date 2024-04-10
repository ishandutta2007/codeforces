#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VALEURS = (1000 * 1000);

int Val[MAX_VALEURS];

int nbTests;
int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
    }
    sort(Val, Val + nbValeurs);
    for (int i = 1; i < nbValeurs; i ++)
    {
        if (Val[i] == Val[i - 1])
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
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