#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

//    <|_|>
//    What is better : to be born good - or to overcome your evil nature through great effort ?

const int MOD = (998244353);
const int MAX_VALEURS = (200 * 1000);

char Val[MAX_VALEURS];

int nbValeurs;

int Expo(int a, int n) {
    if (n == 0)
        return 1;
    int ans = Expo(a, n / 2);
    ans *= ans;
    ans %= MOD;
    if (n & 1)
        ans *= a;
    return ans % MOD;
}

void Read() {
    scanf("%lld", &nbValeurs);
    scanf("%s", Val);
    int nbLibres = 0, nbGroupes = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (i + 1 < nbValeurs && Val[i] == '1' && Val[i + 1] == '1')
        {
            nbGroupes ++;
            i ++;
        }
        else if (Val[i] == '0')
            nbLibres ++;
    }
    int ans = 1;
    for (int i = nbLibres + nbGroupes; i > nbLibres; i --)
    {
        ans *= i;
        ans %= MOD;
    }
    for (int i = 1; i <= nbGroupes; i ++)
    {
        ans *= Expo(i, MOD - 2);
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}