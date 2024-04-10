#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  xiao xiao

const int MAX_VALUES = (2e5);

char String[MAX_VALUES];

void Solve() {
    scanf("%s", String);
    int sz = strlen(String);
    if (String[0] != String[sz - 1])
        String[0] = String[sz - 1];
    printf("%s\n", String);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}