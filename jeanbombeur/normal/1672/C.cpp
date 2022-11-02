#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    int last = 0, first = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i && Val[i] == Val[i - 1])
            last = i;
    }
    for (int i = nbValues - 2; i >= 0; i --)
    {
        if (Val[i] == Val[i + 1])
            first = i;
    }
    if (last - first <= 1)
        printf("0\n");
    else if (last - first == 2)
        printf("1\n");
    else
        printf("%lld\n", last - first - 2);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}