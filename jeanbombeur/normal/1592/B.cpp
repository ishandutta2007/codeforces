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
int Sorted[MAX_VALUES];

int nbValues, maxDiff;

void Solve() {
    scanf("%lld %lld", &nbValues, &maxDiff);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        Sorted[i] = Val[i];
    }
    sort(Sorted, Sorted + nbValues);
    for (int i = nbValues - maxDiff; i < maxDiff; i ++)
    {
        if (Val[i] ^ Sorted[i])
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
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