#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (1e5);

int Val[MAX_VALUES];

int nbValues;

int Gcd(int a, int b) {
    return b ? Gcd(b, a % b) : a;
}

void Read() {
    scanf("%lld", &nbValues);
    int gcd = 1;
    int maxi = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i)
            gcd = Gcd(gcd, Val[i]);
        else
            gcd = Val[i];
        maxi = max(maxi, Val[i]);
    }
    printf("%lld\n", maxi / gcd);
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