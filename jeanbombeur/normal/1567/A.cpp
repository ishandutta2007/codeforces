#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Right on time

const int MAX_VALUES = (2e5);

char Val[MAX_VALUES];

int nbDominos;

void Solve() {
    scanf("%lld %s", &nbDominos, Val);
    for (int i = 0; i < nbDominos; i ++)
    {
        if (Val[i] == 'L' || Val[i] == 'R')
            printf("%c", Val[i]);
        else
            printf("%c", (Val[i] == 'U' ? 'D' : 'U'));
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}