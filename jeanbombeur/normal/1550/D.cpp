#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//    We must be better than this

const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

pair <int, int> Fact[MAX_VALEURS + 1];

int nbValeurs, l, r;

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

int Coef(int k, int n) {
    return (Fact[n].first * ((Fact[k].second * Fact[n - k].second) % MOD)) % MOD;
}

void Read() {
    scanf("%lld %lld %lld", &nbValeurs, &l, &r);
    int ans = 0;
    Fact[0] = {1, 1};
    for (int i = 1; i <= nbValeurs; i ++)
    {
        Fact[i].first = Fact[i - 1].first * i;
        Fact[i].first %= MOD;
        Fact[i].second = Fact[i - 1].second * Expo(i, MOD - 2);
        Fact[i].second %= MOD;
    }
    int moitie = ((nbValeurs + 1) / 2) + 1;
    int nbInf = 0, nbSup = 0, nbDoubles = nbValeurs;
    r --, l --;
    for (int delta = min(abs(r - nbValeurs + 1), abs(l)); nbInf < moitie && nbSup < moitie; delta ++)
    {
        if (delta > 0 && nbInf < moitie && nbSup < moitie)
        {
            ans += Coef(moitie - 1 - nbInf, nbDoubles);
            if ((nbValeurs & 1) && nbInf < moitie - 1)
                ans += Coef(moitie - 2 - nbInf, nbDoubles);
        }
        if (r - delta >= 0 && r - delta < nbValeurs)
            nbInf ++, nbDoubles --;
        if (l + delta >= 0 && l + delta < nbValeurs)
            nbSup ++, nbDoubles --;
    }
    ans %= MOD;
    int nbEntre = max(0LL, (min(abs(r - nbValeurs + 1), abs(l)) - 1)) % MOD;
    ans += Coef(moitie - 1, nbValeurs) * nbEntre;
    ans %= MOD;
    if (nbValeurs & 1)
        ans += Coef(moitie - 2, nbValeurs) * nbEntre;
    printf("%lld\n", ans % MOD);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}