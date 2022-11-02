#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

int nbValues;

void Read() {
    scanf("%lld\n", &nbValues);
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        sum += min(a, b);
        maxi = max(maxi, max(a, b));
    }
    printf("%lld\n", 2 * (sum + maxi));
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