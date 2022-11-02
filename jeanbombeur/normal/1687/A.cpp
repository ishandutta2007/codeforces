#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//

const int MAX_VALUES = 2e5;

int Val[MAX_VALUES];

int nbValues, nbDays;

void Solve() {
    scanf("%lld %lld", &nbValues, &nbDays);
    int sum = 0;
    int best = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i >= nbDays)
            sum -= Val[i - nbDays];
        sum += Val[i];
        best = max(best, sum);
    }
    if (nbDays <= nbValues)
        best += nbDays * (nbDays - 1) / 2;
    else
        best += nbValues * (2 * nbDays - nbValues - 1) / 2;
    printf("%lld\n", best);
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