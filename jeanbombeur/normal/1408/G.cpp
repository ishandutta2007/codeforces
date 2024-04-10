#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
const int MAX_NOEUDS = (1500);
const int MOD = 998244353;

int Pere[MAX_NOEUDS];

long long NBAretes[MAX_NOEUDS];

long long DP[MAX_NOEUDS][MAX_NOEUDS];

pair <int, pair <int, int>> Aretes[MAX_NOEUDS * MAX_NOEUDS];

int nbNoeuds;

int Find(int noeud) {
    if (Pere[noeud] < 0)
    {
        return noeud;
    }
    return Pere[noeud] = Find(Pere[noeud]);
}

void Merge(int a, int b) {
    int t = - Pere[a];
    int u = - Pere[b];
    vector <long long> nouv;
    for (int i = 0; i < t + u; i ++)
    {
        long long act = 0;
        for (int j = 0; j < min(t, i); j ++)
        {
            act += DP[a][j] * DP[b][i - j - 1];
            act %= MOD;
        }
        nouv.push_back(act);
    }
    if (t > u)
    {
        for (int i = 0; i < t + u; i ++)
        {
            DP[a][i] = nouv[i];
        }
        return;
    }
    for (int i = 0; i < t + u; i ++)
    {
        DP[b][i] = nouv[i];
    }
    return;
}

void Union(int a, int b) {
    int r = Find(a);
    int s = Find(b);
    int t = - Pere[r];
    int u = - Pere[s];
    if (r == s)
    {
        if (++ NBAretes[r] == (t * (t - 1)) / 2)
        {
            DP[r][0] = 1;
        }
        return;
    }
    if (t > u)
    {
        Merge(r, s);
        Pere[r] -= u;
        Pere[s] = r;
        t = - Pere[r];
        NBAretes[r] += NBAretes[s];
        if (++ NBAretes[r] == (t * (t - 1)) / 2)
        {
            DP[r][0] = 1;
        }
        return;
    }
    Merge(r, s);
    Pere[s] -= t;
    Pere[r] = s;
    NBAretes[s] += NBAretes[r];
    u = - Pere[s];
    if (++ NBAretes[s] == (u * (u - 1)) / 2)
    {
        DP[s][0] = 1;
    }
    return;
}

void Read() {
    scanf("%d", &nbNoeuds);
    int cur = 0;
    for (int i = 0; i < nbNoeuds; i ++)
    {
        Pere[i] = -1;
        DP[i][0] = 1;
    }
    for (int i = 0; i < nbNoeuds; i ++)
    {
        for (int j = 0; j < nbNoeuds; j ++)
        {
            int a;
            scanf("%d", &a);
            if (i < j)
            {
                Aretes[cur ++] = make_pair(a, make_pair(i, j));
            }
        }
    }
    sort(Aretes, Aretes + cur);
    for (int i = 0; i < cur; i ++)
    {
        Union(Aretes[i].second.first, Aretes[i].second.second);
    }
    int root = Find(0);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        printf("%lld ", DP[root][i]);
    }
    printf("\n");
    return;
}


int main() {
    Read();
    return 0;
}