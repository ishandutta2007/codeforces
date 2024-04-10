#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5 + 1);

int nbValues;

void Read() {
    int n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    printf((a + b + 1 < n || a + b == 2 * n) ? "Yes\n" : "No\n");
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