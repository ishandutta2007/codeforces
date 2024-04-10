#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues, diff;

void Read() {
    scanf("%lld %lld", &nbValues, &diff);
    int ans = 0;
    int mini = 1 << 30, maxi = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        mini = min(Val[i], mini);
        maxi = max(Val[i], maxi);
        if (maxi - mini > 2 * diff)
        {
            ans ++;
            maxi = mini = Val[i];
        }
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