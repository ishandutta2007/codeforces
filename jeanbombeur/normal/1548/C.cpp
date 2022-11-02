#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
//  <|_|>
 
//  Why do we fall, sir ?
 
const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEURS = (4000 * 1000);
 
int Ans[MAX_VALEURS];
 
int Fact[MAX_VALEURS];
int InvFact[MAX_VALEURS];
 
int nbJours, nbRequetes;
 
int InverseMod(int a, int n) {
    return n <= 1 ? n : n - (InverseMod(n % a, a) * n - 1) / a;
}

int Expo(int a) {
    int ans = 1;
    int cur = a;
    for (int i = 1; i <= MOD - 2; i <<= 1)
    {
        if ((MOD - 2) & i)
            ans = (ans * cur) % MOD;
        cur = (cur * cur) % MOD;
    }
    return ans;
}
 
int Choose(int n, int k) {
    return (Fact[n] * ((InvFact[k] * InvFact[n - k]) % MOD)) % MOD;
}
 
void Read() {
    scanf("%lld %lld", &nbJours, &nbRequetes);
    Fact[0] = InvFact[0] = 1;
    for (int i = 1; i <= 3 * nbJours + 3; i ++)
    {
        Fact[i] = (Fact[i - 1] * i) % MOD;
    }
    InvFact[3 * nbJours + 3] = Expo(Fact[3 * nbJours + 3]);
    for (int i = 3 * nbJours + 2; i > 0; i --)
    {
        InvFact[i] = (InvFact[i + 1] * (i + 1)) % MOD;
    }
    Ans[0] = nbJours + 1;
    Ans[1] = 3 * (nbJours * (nbJours + 1));
    Ans[1] %= MOD;
    Ans[1] = (Ans[1] * Expo(2)) % MOD;
    int inverse = Expo(3);
    for (int i = 2; i <= 3 * nbJours; i ++)
    {
        Ans[i] = Choose(3 * nbJours + 3, i + 1) - Ans[i - 2] - 3 * Ans[i - 1];
        Ans[i] %= MOD;
        if (Ans[i] < 0)
            Ans[i] += MOD;
        Ans[i] = (Ans[i] * InverseMod(3, MOD)) % MOD;
    }
    for (int i = 0; i < nbRequetes; i ++)
    {
        int a;
        scanf("%lld", &a);
        printf("%lld\n", Ans[a]);
    }
    return;
}
 
signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
        Read();
    return 0;
}