#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    int sum = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        sum ^= Val[i];
    }
    if (nbValeurs % 2 == 0 && sum > 0)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n%d\n", 2 * ((nbValeurs - 1) / 2));
    for (int i = 2; i < nbValeurs; i += 2)
    {
        printf("1 %d %d\n", i, i + 1);
    }
    for (int i = 2; i < nbValeurs; i += 2)
    {
        printf("1 %d %d\n", i, i + 1);
    }
    return;
}

void Solve() {
    return;
}

int main() {
    Read();
    return 0;
}