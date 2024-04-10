#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

map <int, long long> m[N], cnt[N];
vector <int> e[N];
int t[N], c[N];
long long ans[N];

int uni(int a, int b) {
    if (cnt[a].size() < cnt[b].size())
        swap(a, b);
    for (map<int, long long> :: iterator it = cnt[b].begin(); it != cnt[b].end(); ++it) {
        int v = (*it).first, c = (*it).second;
        m[a][cnt[a][v]] -= v;
        cnt[a][v] += c;
        m[a][cnt[a][v]] += v;
    }
    return a;
}

void dfs(int u, int pr) {
    cnt[u][c[u]] = 1;
    m[u][1] += c[u];
    t[u] = u;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs(e[u][i], u);
        t[u] = uni(t[u], t[e[u][i]]);
    }
    map <int, long long> :: iterator it = m[t[u]].end();
    --it;
    ans[u] = (*it).second;
}

int main() {
    int i, j, k, n, q, x, y;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> c[i];
    for (i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    for (i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}