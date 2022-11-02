#include <iostream>
#include <cstdio>
using namespace std;

//    <|_|>

const int MAX_VALEURS = 1000;

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    int maximum = 0;
    int sum = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        sum += Val[i];
        maximum = max(maximum, sum);
    }
    int ans = maximum;
    maximum = 0;
    sum = 0;
    scanf("%d", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        sum += Val[i];
        maximum = max(maximum, sum);
    }
    printf("%d\n", ans + maximum);
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