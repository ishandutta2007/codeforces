#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Spared no expense

const int MAX_DIGITS = (2e4 + 1);

char Digits[MAX_DIGITS];

int nbDigits;

void Solve() {
    scanf("%lld %s", &nbDigits, Digits);
    int mid = nbDigits / 2;
    for (int i = 0; i < nbDigits; i ++)
    {
        if (Digits[i] == '0')
        {
            if (i < mid)
                printf("%lld %lld %lld %lld\n", i + 1, i + mid + 1, i + 2, i + mid + 1);
            else
                printf("%lld %lld %lld %lld\n", i - mid + 1, i + 1, i - mid + 1, i);
            return;
        }
    }
    printf("1 %lld 1 %lld\n", 2 * mid, mid);
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