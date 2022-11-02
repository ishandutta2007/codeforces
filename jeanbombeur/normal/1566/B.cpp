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

char Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%s", Val);
    nbValues = strlen(Val);
    int ans = Val[nbValues - 1] == '0';
    for (int i = 1; i < nbValues; i ++)
    {
        ans += (Val[i] == '1' && Val[i - 1] == '0');
    }
    printf("%lld\n", min(2LL, ans));
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