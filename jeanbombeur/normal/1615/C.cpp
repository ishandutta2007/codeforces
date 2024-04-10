#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (2e5);

char Act[MAX_VALUES];
char Goal[MAX_VALUES];

int nbCandles;

void Solve() {
    scanf("%lld", &nbCandles);
    scanf("%s %s", Act, Goal);
    int sumA = 0, sumG = 0;
    int diff = 0;
    int same = 0;
    for (int i = 0; i < nbCandles; i ++)
    {
        sumA += Act[i] == '1';
        sumG += Goal[i] == '1';
        diff += Act[i] != Goal[i];
        same += Act[i] == '1' && Goal[i] == '1';
    }
    if (sumA != sumG && (nbCandles - sumA + 1) != sumG)
    {
        printf("-1\n");
        return;
    }
    if (sumA == 0)
    {
        printf("0\n");
        return;
    }
    if (sumA == sumG && (nbCandles - sumA + 1) != sumG)
    {
        printf("%lld\n", diff);
        return;
    }
    if ((nbCandles - sumA + 1) == sumG && sumA != sumG)
    {
        printf("%lld\n", nbCandles - diff + (same ? 0 : 1));
        return;
    }
    printf("%lld\n", min(diff, nbCandles - diff + (same ? 0 : 1)));
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