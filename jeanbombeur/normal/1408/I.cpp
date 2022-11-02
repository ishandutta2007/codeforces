#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

const int MOD = 998244353;
const int MAX_LOG = 17;
const int MAX_NOMBRES = (1 << MAX_LOG);

int Valeurs[MAX_NOMBRES];

int CoefBinomial[MAX_LOG][MAX_LOG];

pair <int, int> PlusGrand[MAX_NOMBRES];

int DP[MAX_LOG][MAX_NOMBRES];

int nbNombres, nbEtapes, logMax;

int ExpRapide(int a, int n) {
    if (n == 1)
    {
        return a;
    }
    int ans = ExpRapide(a, n / 2);
    ans *= ans;
    ans %= MOD;
    if (n % 2 == 1)
    {
        ans *= a;
    }
    return ans % MOD;
}

int Inverse(int a) {
    return ExpRapide(a, MOD - 2);
}

void Read() {
    scanf("%lld%lld%lld", &nbNombres, &nbEtapes, &logMax);
    for (int i = 0; i < nbNombres; i ++)
    {
        scanf("%lld", &Valeurs[i]);
    }
    for (int i = 0; i < MAX_LOG; i ++)
    {
        CoefBinomial[i][0] = 1;
        for (int j = 1; j <= i; j ++)
        {
            CoefBinomial[i][j] = CoefBinomial[i - 1][j - 1] + CoefBinomial[i - 1][j];
            CoefBinomial[i][j] %= MOD;
        }
    }
    return;
}

void Print() {
    for (int i = 0; i <= nbEtapes; i ++)
    {
        for (int j = 0; j < (1 << logMax); j ++)
        {
            printf("%lld ", DP[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}


void Solve() {
    for (int i = 0; i < nbNombres; i ++)
    {
        for (int k = 1; k <= nbEtapes; k ++)
        {
            PlusGrand[i].first = max(PlusGrand[i].first, (Valeurs[i] ^ (Valeurs[i] - k)));
        }
        PlusGrand[i].second = i;
    }
    sort(PlusGrand, PlusGrand + nbNombres);
    int logAct = 0;
    DP[0][0] = 1;
    for (int i = 0; i < nbNombres; i ++)
    {
        int id = PlusGrand[i].second;
        for (int j = nbEtapes - 1; j >= 0; j --)
        {
            for (int k = 0; k < (1 << logAct); k ++)
            {
                for (int l = 1; l <= nbEtapes - j; l ++)
                {
                    DP[j + l][k ^ Valeurs[id] ^ (Valeurs[id] - l)] += DP[j][k] * CoefBinomial[nbEtapes - j][l];
                    DP[j + l][k ^ Valeurs[id] ^ (Valeurs[id] - l)] %= MOD;
                    //printf("%lld %lld %lld\n", j, k, l);
                    //Print();
                }
            }
        }
        printf("\n\n");
        while ((1 << logAct) <= PlusGrand[i].first)
        {
            logAct ++;
        }
    }
    int sum = 0;
    for (int i = 0; i < nbNombres; i ++)
    {
        sum ^= Valeurs[i];
    }
    int denom = Inverse(ExpRapide(nbNombres, nbEtapes));
    for (int i = 0; i < (1 << logMax); i ++)
    {
        printf("%lld ", (DP[nbEtapes][i ^ sum] * denom) % MOD);
    }
    printf("\n");
    return;
}

signed main() {
    Read();
    Solve();
    //Print();
    return 0;
}