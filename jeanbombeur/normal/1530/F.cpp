#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  With great power comes great responsability

//  This is my gift, my curse

//  When the student is ready, the teacher will appear. When the student is truly ready, the teacher will disappear.

//  There are no accidents

//  The hardest choices require the strongest wills

//  You're not the only one cursed with knowledge

//  What is better - to be born good, or to overcome your evil nature with great effort ?

//  We must be better

const int MOD = (31607);
const int MAX_VALEURS = (200 * 1000);
const int MAX_LIGNES = (21);
const int MAX_MASK = (1 << 21);

int DP[MAX_LIGNES][MAX_MASK];

int Proba[MAX_LIGNES][MAX_LIGNES];

int nbLignes;

int Expo(int a, int n) {
    int ans = 1;
    int cur = a;
    for (int i = 1; i <= n; i <<= 1)
    {
        if (i & n)
            ans = (ans * cur) % MOD;
        cur = (cur * cur) % MOD;
    }
    return ans;
}

void Read() {
    scanf("%lld", &nbLignes);
    int inverse = Expo(10000, MOD - 2);
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbLignes; j ++)
        {
            scanf("%lld", &Proba[i][j]);
            Proba[i][j] = (Proba[i][j] * inverse) % MOD;
        }
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        DP[i][0] = 1;
        for (int j = 0; j < nbLignes; j ++)
        {
            for (int m = 0; m < (1 << j); m ++)
            {
                DP[i][m ^ (1 << j)] = DP[i][m] * Proba[i][j];
                DP[i][m ^ (1 << j)] %= MOD;
            }
        }
    }
    return;
}

int FindProba(int id, int mask) {
    int proba = 1;
    if (id == nbLignes + 2)
    {
        for (int i = 0; i < nbLignes; i ++)
        {
            int newMask = mask >> 2;
            if (mask & 1)
                newMask |= (1 << i);
            if (mask & 2)
                newMask |= (1 << (nbLignes - i - 1));
            proba *= (1 + MOD - DP[i][((1 << nbLignes) - 1) ^ newMask]);
            proba %= MOD;
        }
        return proba;
    }
    if (id == 0)
    {
        for (int i = 0; i < nbLignes; i ++)
        {
            proba *= Proba[i][i];
            proba %= MOD;
        }
    }
    else if (id == 1)
    {
        for (int i = 0; i < nbLignes; i ++)
        {
            if (!(mask & 1) || nbLignes - i - 1 != i)
            {
                proba *= Proba[i][nbLignes - i - 1];
                proba %= MOD;
            }
        }
    }
    else
    {
        id -= 2;
        for (int i = 0; i < nbLignes; i ++)
        {
            if ((!(mask & 1) || i != id) && (!(mask & 2) || i != nbLignes - id - 1))
            {
                proba *= Proba[i][id];
                proba %= MOD;
            }
        }
        id += 2;
    }
    int ans = (FindProba(id + 1, mask) - FindProba(id + 1, mask | (1 << id)) * proba) % MOD;
    if (ans < 0)
        ans += MOD;
    return ans;
}

void Solve() {
    printf("%lld\n", (1 + MOD - FindProba(0, 0)) % MOD);
    return;
}

signed main() {
    Read();
    Solve();
    return 0;
}