#include <bits/stdc++.h>
using namespace std;
const int N = 1.5E5, P = 998244353;
int n, q;
vector<int> e[N];
int sum[N], sz[N], top[N], in[N], dep[N], parent[N], out[N];
int dfs_now;
int fen[N + 1];
void add(int x, int y) {
    while (x <= N) {
        fen[x] = (fen[x] + y) % P;
        x += x & -x;
    }
}
void add(int l, int r, int x) {
    add(l + 1, x);
    add(r + 1, P - x);
}
int get(int x) {
    ++x;
    int result = 0;
    while (x > 0) {
        result = (result + fen[x]) % P;
        x -= x & -x;
    }
    return result;
}
int power(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp & 1)
            result = 1LL * result * base % P;
        base = 1LL * base * base % P;
        exp >>= 1;
    }
    return result;
}
void dfsSz(int u) {
    sz[u] = 1;
    if (parent[u] != -1)
        e[u].erase(find(e[u].begin(), e[u].end(), parent[u]));
    for (int &v : e[u]) {
        dep[v] = dep[u] + 1;
        parent[v] = u;
        dfsSz(v);
        sz[u] += sz[v];
        if (sz[v] > sz[e[u][0]])
            swap(v, e[u][0]);
    }
}
void dfsHLD(int u) {
    in[u] = dfs_now++;
    for (int v : e[u]) {
        top[v] = v == e[u][0] ? top[u] : v;
        dfsHLD(v);
    }
    out[u] = dfs_now;
}
void modify(int v, int d) {
    add(0, in[v], 1LL * d * sz[v] % P);
    add(out[v], n, 1LL * d * sz[v] % P);
    add(in[v], in[v] + 1, 1LL * d * n % P);
    if (!e[v].empty()) {
        int u = e[v][0];
        add(in[u], out[u], 1LL * d * (n - sz[u]) % P);
    }
    sum[v] = (sum[v] + d) % P;
}
int query(int v) {
    int result = get(in[v]);
    while (v != -1) {
        v = top[v];
        if (parent[v] != -1)
            result = (result + 1LL * sum[parent[v]] * (n - sz[v])) % P;
        v = parent[v];
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        e[--u].push_back(--v);
        e[v].push_back(u);
    }
    parent[0] = -1;
    dfsSz(0);
    dfsHLD(0);
    int inv = power(n, P - 2);
    for (int i = 0; i < q; ++i) {
        int op ;
        cin >> op;
        if (op == 1) {
            int v, d;
            cin >> v >> d;
            modify(--v, d);
        } else {
            int v;
            cin >> v;
            cout << 1LL * query(--v) * inv % P << "\n";
        }
    }
    return 0;
}