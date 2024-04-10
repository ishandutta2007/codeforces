#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

//   <|_|>

const int MAX_VALEURS = (100 * 1000);

//int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    int a = sqrt(nbValeurs / 2);
    if (2 * a * a == nbValeurs)
    {
        printf("YES\n");
        return;
    }
    a = sqrt(nbValeurs / 4);
    if (4 * a * a == nbValeurs)
    {
        printf("YES\n");
        return;
    }
    printf("NO\n");
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