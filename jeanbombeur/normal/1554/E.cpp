#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

const int MOD = (998244353);
const int MAX_VALEURS = (200 * 1000);

vector <int> Voisins[MAX_VALEURS];

int Ans[MAX_VALEURS];

int nbNoeuds;

int Dfs(int noeud, int pere, int k) {
    int sum = 0;
    for (int dest : Voisins[noeud])
    {
        if (dest != pere)
        {
            int r = Dfs(dest, noeud, k);
            if (r < 0)
                return -1;
            sum += r;
        }
    }
    if (sum % k == 0)
        return 1;
    if ((sum + 1) % k == 0)
        return 0;
    return -1;
}

void Read() {
    scanf("%lld", &nbNoeuds);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        Voisins[i].clear();
    }
    fill_n(Ans, nbNoeuds + 1, 0);
    Ans[1] = 1;
    for (int i = 1; i < nbNoeuds; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Voisins[-- a].push_back(-- b);
        Voisins[b].push_back(a);
        Ans[1] *= 2;
        if (Ans[1] >= MOD)
            Ans[1] -= MOD;
    }
    for (int i = 2; i < nbNoeuds; i ++)
    {
        if ((nbNoeuds - 1) % i == 0)
        {
            Ans[i] = Dfs(0, 0, i);
        }
    }
    for (int i = nbNoeuds - 1; i > 0; i --)
    {
        for (int j = 2 * i; j < nbNoeuds; j += i)
        {
            Ans[i] -= Ans[j];
        }
        Ans[i] = max(Ans[i], 0LL);
    }
    for (int i = 1; i <= nbNoeuds; i ++)
    {
        printf("%lld ", Ans[i]);
    }
    printf("\n");
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