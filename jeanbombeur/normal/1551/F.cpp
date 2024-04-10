#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  Ah shit, here we go again

const int MOD = (1e9 + 7);
const int MAX_VALEURS = (101);

vector <int> Voisins[MAX_VALEURS];

int Occ[MAX_VALEURS];

int DP[MAX_VALEURS][MAX_VALEURS];

int nbNoeuds, taille;

void Dfs(int noeud, int pere, int dist) {
    Occ[dist] ++;
    for (int dest : Voisins[noeud])
    {
        if (dest != pere)
            Dfs(dest, noeud, dist + 1);
    }
    return;
}

void Solve() {
    scanf("%lld %lld", &nbNoeuds, &taille);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        Voisins[i].clear();
    }
    for (int i = 1; i < nbNoeuds; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Voisins[-- a].push_back(-- b);
        Voisins[b].push_back(a);
    }
    if (taille == 2)
    {
        printf("%lld\n", (nbNoeuds * (nbNoeuds - 1)) / 2);
        return;
    }
    int ans = 0;
    for (int i = 0; i < nbNoeuds; i ++)
    {
        for (int j = 0; j < nbNoeuds; j ++)
        {
            fill_n(DP[j], nbNoeuds, 0LL);
            DP[j][0] = 1;
        }
        for (int dest : Voisins[i])
        {
            fill_n(Occ, nbNoeuds, 0LL);
            Dfs(dest, i, 1);
            for (int d = 0; d < nbNoeuds; d ++)
            {
                for (int j = nbNoeuds - 1; j > 0; j --)
                {
                    DP[d][j] += DP[d][j - 1] * Occ[d];
                    DP[d][j] %= MOD;
                }
            }
        }
        for (int d = 0; d < nbNoeuds; d ++)
        {
            ans += DP[d][taille];
        }
        ans %= MOD;
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