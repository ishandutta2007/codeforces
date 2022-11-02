#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (1e6);

int Val[MAX_VALUES];

int nbValues;

void Read() {
    scanf("%lld\n", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    sort(Val, Val + nbValues);
    int ans = 0;
    for (int i = nbValues - 1; i > 1; i --)
    {
        ans = max(ans, 2 * Val[i] - Val[i - 1] - Val[0]);
    }
    for (int i = 0; i + 2 < nbValues; i ++)
    {
        ans = max(ans, Val[i + 1] + Val[nbValues - 1] - 2 * Val[i]);
    }
    printf("%lld\n", ans);
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