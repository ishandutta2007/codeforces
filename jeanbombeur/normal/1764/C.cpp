#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Read() {
    scanf("%lld", &nbValues);
    int best = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    sort(Val, Val + nbValues);
    for (int i = 1; i < nbValues; i ++)
    {
        if (Val[i] != Val[i - 1])
            best = max(best, i * (nbValues - i));
    }
    if (!best)
        best = nbValues / 2;
    printf("%lld\n", best);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}