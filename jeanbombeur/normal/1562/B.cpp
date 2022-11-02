#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Spared no expense

const int MAX_DIGITS = (50);

int Digits[MAX_DIGITS];

int Occ[10];

int nbDigits;

void Solve() {
    scanf("%lld\n", &nbDigits);
    fill_n(Occ, 10, 0);
    for (int i = 0; i < nbDigits; i ++)
    {
        char c = getchar();
        Digits[i] = c - '0';
        Occ[Digits[i]] ++;
    }
    if (nbDigits == 1)
    {
        printf("1\n%lld\n", Digits[0]);
        return;
    }
    for (int i = 1; i < 10; i ++)
    {
        if (i != 2 && i != 3 && i != 5 && i != 7 && Occ[i] > 0)
        {
            printf("1\n%lld\n", i);
            return;
        }
    }
    for (int i = 1; i < 10; i ++)
    {
        if (i == 2 || i == 3 || i == 5 || i == 7)
        {
            if (Occ[i] > 1)
            {
                printf("2\n%lld\n", 11 * i);
                return;
            }
        }
    }
    for (int i = 1; i < nbDigits; i ++)
    {
        if (Digits[i] == 2 || Digits[i] == 5)
        {
            printf("2\n%lld\n", 10 * Digits[0] + Digits[i]);
            return;
        }
    }
    if (nbDigits == 2)
    {
        printf("2\n%lld\n", 10 * Digits[0] + Digits[1]);
        return;
    }
    printf("2\n%lld\n", 10 * Digits[0] + 7);
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