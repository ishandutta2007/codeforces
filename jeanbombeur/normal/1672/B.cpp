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
    int sum = 0;
    nbValues = strlen(Val);
    int ans = 1;
    for (int i = 0; i < nbValues; i ++)
    {
        sum += (Val[i] == 'A' ? 1 : -1);
        ans &= (sum >= 0);
    }
    if (ans && Val[nbValues - 1] == 'B')
        printf("YES\n");
    else
        printf("NO\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}