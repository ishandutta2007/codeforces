#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Right on time

const int MAX_VALUES = (2e5);

int Digits[MAX_VALUES];

int DP[MAX_VALUES][2];

int n;

void Solve() {
    scanf("%lld", &n);
    int nbDigits = 0;
    while (n > 0)
        Digits[nbDigits ++] = n % 10, n /= 10;
    int ans = 0;
    for (int m = 0; m < (1 << nbDigits); m += 4)
    {
        int cur = 1;
        for (int j = 0; j < nbDigits; j ++)
        {
            if (!((m >> (j + 2)) & 1))
                cur *= (Digits[j] + 1 - ((m >> j) & 1));
            else
                cur *= (9 - Digits[j] + ((m >> j) & 1));
        }
        ans += cur;
    }
    printf("%lld\n", ans - 2);
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