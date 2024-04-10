#include <bits/stdc++.h>

#define emb emplace_back

using std::cin;
using std::cout;
using std::endl;

typedef std::vector<int> vector;

const int N = 200054;
const int M = N << 1;

int n, E = 0, ans;
int to[M], first[N], next[M];
int dep[N], size[N], prf[N];
vector chain[N];

inline int query(char type, int node) {
    return cout << type << ' ' << node << endl, cin >> node, node;
}

inline void addedge(int u, int v) {
    to[++E] = v, next[E] = first[u], first[u] = E;
    to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs_pre(int x, int px = 0) {
    int i, y, &z = prf[x];
    size[x] = 1;
    for (i = first[x]; i; i = next[i]) {
        if ((y = to[i]) != px) {
            dep[y] = dep[x] + 1, dfs_pre(y, x);
            size[y] > size[z] ? z = y : 0;
            size[x] += size[y];
        }
    }
    if (z) std::swap(chain[x], chain[z]);
    chain[x].emb(x);
}

int dfs(int x) {
    int cnt = chain[x].size() - 1, remain = ans - dep[x],
        dist = query(100, chain[x].back());
    int i = (cnt + remain - dist) / 2, y = chain[x][i];
    return dep[y] == ans ? y : dfs(query(115, y));
}

int main() {
    int i, u, v;
    std::ios::sync_with_stdio(false), cin.tie(NULL);
    scanf("%d", &n);
    for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
    ans = query(100, 1), dfs_pre(1);
    for (i = 1; i <= n; ++i) {
        if (!chain[i].empty()) std::reverse(chain[i].begin(), chain[i].end());
    }
    cout << '!' << ' ' << dfs(1) << endl;
    return 0;
}