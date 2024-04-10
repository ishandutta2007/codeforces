#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  I've been looking forward to this

//  <|_|>

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    int sum = 0;
    int last = 0;
    int ok = 1;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        sum += Val[i];
        if (Val[i])
            last = i;
    }
    int nvsum = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        nvsum += Val[i];
        if (nvsum < 0 || (nvsum == 0 && i < last))
            ok = 0;
    }
    if (sum != 0)
        ok = 0;
    if (ok)
        printf("Yes\n");
    else
        printf("No\n");
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