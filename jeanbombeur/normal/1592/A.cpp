#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm back !

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues, health;

void Solve() {
    scanf("%lld %lld", &nbValues, &health);
    int max1 = 0, max2 = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (Val[i] > max1)
            max2 = max1, max1 = Val[i];
        else if (Val[i] > max2)
            max2 = Val[i];
    }
    int d = health / (max1 + max2);
    health -= d * (max1 + max2);
    d *= 2;
    if (health > 0)
        health -= max1, d ++;
    if (health > 0)
        d ++;
    printf("%lld\n", d);
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