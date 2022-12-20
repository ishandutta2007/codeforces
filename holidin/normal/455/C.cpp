#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;

int d[N], t[N], l[N];
bool use[N];
vector <int> v[N], e[N];

void uni(int a, int b) {
    if (v[a].size() < v[b].size())
        swap(a, b);
    for (int i = 0; i < v[b].size(); ++i) {
        v[a].push_back(v[b][i]);
        t[v[b][i]] = a;
    }
    d[a] = max((d[a] + 1) / 2 + (d[b] + 1) / 2 + 1, max(d[a], d[b]));
}

void dfs(int u, int top) {
    int dx = 0;
    use[u] = true;
    v[top].push_back(u);
    t[u] = top;
    l[u] = 0;
    for (int i = 0; i < e[u].size(); ++i)
    if (!use[e[u][i]]) {
        dfs(e[u][i], top);
        d[top] = max(d[top], l[e[u][i]] + 1 + l[u]);
        l[u] = max(l[u], l[e[u][i]] + 1);
    }
}

int main() {
    int i, j, k, n, m, q, a, b, p, top = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (i = 0; i < m; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (i = 1; i <= n; ++i)
    if (!use[i]) {
        ++top;
        dfs(i, top);
    }
    for (i = 0; i < q; ++i) {
        cin >> p;
        if (p == 1) {
            cin >> j;
            cout << d[t[j]] << "\n";
        } else {
            cin >> a >> b;
            if (t[a] != t[b])
                uni(t[a], t[b]);
        }
    }

}