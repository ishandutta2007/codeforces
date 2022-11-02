#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;

//  <|_|>

//  A wizard is never late nor early. He arrives precisely when he means to

const int MAX_CHIFFRES = (30);

int Chiffres[2][MAX_CHIFFRES];

int NbMin(int a, int b) {
    int szA = 0, szB = 0;
    while (a > 0)
        Chiffres[0][szA ++] = a % 10, a /= 10;
    while (b > 0)
        Chiffres[1][szB ++] = b % 10, b /= 10;
    int ans = szA + szB;
    szB --;
    while (-- szA >= 0)
    {
        if (szB >= 0 && Chiffres[0][szA] == Chiffres[1][szB])
            ans -= 2, szB --;
    }
    return ans;
}

void Solve() {
    int n;
    scanf("%lld", &n);
    int ans = 42666;
    for (int i = 0; i < 63; i ++)
    {
        ans = min(ans, NbMin(n, (1LL << i)));
    }
    printf("%lld\n", ans);
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