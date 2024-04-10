#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10, MAXM = 20, MAXK = 1E6 + 100;
const int MOD = 1E9 + 7;

int n;
vector<int> E[MAXN];
vector<int> G[MAXN];
int type[MAXN];

int depth[MAXN];
int p[MAXN][MAXM];
int f[MAXN], g[MAXN];

int ans;
int exp2m[MAXK];

void DFS1(int u, int pre){
    depth[u] = depth[pre] + 1;
    p[u][0] = pre;
    for (int i = E[u].size() - 1; i >= 0; --i)
        if (E[u][i] == pre)
            type[u] = G[u][i];
        else
            DFS1(E[u][i], u);
}

void DFS2(int u, int pre){
    for (int i = E[u].size() - 1; i >= 0; --i)
        if (E[u][i] != pre){
            DFS2(E[u][i], u);
            f[u] += f[E[u][i]];
            g[u] += g[E[u][i]];
        }
    if (type[u] == 1)
        ans = (ans + exp2m[f[u]]) % MOD;
    if (type[u] == 0)
        ans = (ans + exp2m[g[u]]) % MOD;
}

void build(){
    for (int j = 1; j < MAXM; ++j)
        for (int i = 1; i <= n; ++i)
            p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA(int u, int v){
    if (depth[u] > depth[v])
        swap(u, v);
    int diff = depth[v] - depth[u];
    for (int i = 0; diff; ++i, diff >>= 1)
        if (diff & 1)
            v = p[v][i];
    if (u == v)
        return u;

    for (int i = MAXM - 1; i >= 0; --i)
        if (p[u][i] != p[v][i])
            u = p[u][i], v = p[v][i];
    return p[u][0];
}

int main(){
    exp2m[0] = 0;
    for (int i = 1; i < MAXK; ++i)
        exp2m[i] = (exp2m[i - 1] << 1 | 1) % MOD;

    scanf("%d", &n);
    for (int i = 1; i < n; ++i){
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        E[u].push_back(v);
        E[v].push_back(u);
        if (d){
            G[u].push_back(0);
            G[v].push_back(d);
        }
        else{
            G[u].push_back(-1);
            G[v].push_back(-1);
        }
    }
    type[1] = -1;
    DFS1(1, 0);
    build();

    int K;
    scanf("%d", &K);
    for (int u = 1, v, i = 0; i < K; ++i){
        scanf("%d", &v);
        int w = LCA(u, v);
        ++f[u], ++g[v];
        --f[w], --g[w];
        u = v;
    }

    ans = 0;
    DFS2(1, 0);
    printf("%d\n", ans);
    return 0;
}