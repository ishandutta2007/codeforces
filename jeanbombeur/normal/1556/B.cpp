#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Hello there

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    int nb = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        nb += Val[i] &= 1;
    }
    if (nb != nbValues / 2 && nb != (nbValues + 1) / 2)
    {
        printf("-1\n");
        return;
    }
    int ans = nbValues * nbValues;
    int first = 1;
    if (nbValues > 2 * nb)
        first = 0;
    int sum = 0;
    int cur = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        cur += abs(sum - (i + 1) / 2);
        sum += Val[i] == first;
    }
    ans = min(ans, cur);
    if (nbValues == 2 * nb)
    {
        first ^= 1;
        sum = 0, cur = 0;
        for (int i = 0; i < nbValues; i ++)
        {
            cur += abs(sum - (i + 1) / 2);
            sum += Val[i] == first;
        }
        ans = min(ans, cur);
    }
    printf("%lld\n", ans);
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