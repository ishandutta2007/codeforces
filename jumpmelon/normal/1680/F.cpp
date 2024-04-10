#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
int n, codd, COdd[MAXN + 5], CEven[MAXN + 5];
int Vis[MAXN + 5], Dep[MAXN + 5];
int Col[MAXN + 5];
vector<int> G[MAXN + 5];
int pu, pv;

void DFS(int u, int fa) {
    Vis[u] = 1;
    Dep[u] = Dep[fa] + 1;
    for (int v : G[u])
        if (v != fa) {
            if (!Vis[v]) {
                DFS(v, u);
            } else if (Dep[u] > Dep[v]) {
                if ((Dep[v] - Dep[u]) & 1) {
                    // even loop
                    CEven[u]++;
                    CEven[v]--;
                } else {
                    pu = u;
                    pv = v;
                    codd++;
                    COdd[u]++;
                    COdd[v]--;
                }
            }
        }
}

void DFS2(int u) {
    for (int v : G[u])
        if (Dep[v] == Dep[u] + 1) {
            DFS2(v);
            COdd[u] += COdd[v];
            CEven[u] += CEven[v];
            if (COdd[v] == codd && !CEven[v]) {
                pu = u;
                pv = v;
            }
        }
}

void DFS3(int u) {
    for (int v : G[u])
        if (Col[v] == -1) {
            Col[v] = Col[u] ^ 1;
            DFS3(v);
        }
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int m;
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++)
            G[i].clear();
        codd = 0;
        memset(COdd + 1, 0, sizeof(int[n]));
        memset(CEven + 1, 0, sizeof(int[n]));
        memset(Vis + 1, 0, sizeof(int[n]));
        memset(Col + 1, -1, sizeof(int[n]));

        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
            if (!Vis[i])
                DFS(i, 0);
        
        bool flag = 1;

        if (codd == 0) {
            for (int i = 1; i <= n; i++)
                if (Col[i] == -1) {
                    Col[i] = 0;
                    DFS3(i);
                }
        } else {
            if (codd > 1) {
                pu = pv = -1;
                for (int i = 1; i <= n; i++)
                    if (Dep[i] == 1)
                        DFS2(i);
            }
            if (pu == -1) {
                puts("NO");
                flag = 0;
            }
            Col[pu] = Col[pv] = 1;
            DFS3(pu);
            DFS3(pv);
            for (int i = 1; i <= n; i++)
                if (Col[i] == -1) {
                    Col[i] = 0;
                    DFS3(i);
                }
        }
        if (flag) {
            puts("YES");
            for (int i = 1; i <= n; i++)
                putchar(Col[i] + '0');
            putchar('\n');
        }
    }
    return 0;
}