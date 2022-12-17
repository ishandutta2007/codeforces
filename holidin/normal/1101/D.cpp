#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 10;
const int inf = 1e9;


int p[N], l[N], dp[N];
bool is[N], use[N];
vector <int> e[N], sp[N], v[N];

void dfs(int u, int pr) {
    p[u] = pr;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        dfs(e[u][i], u);
}

int dfs1(int u, int pr) {
    use[u] = true;
    vector <int> v;
    dp[u] = 1;
    l[u] = 0;
    v.push_back(0);
    v.push_back(0);
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs1(e[u][i], u);
        v.push_back(l[e[u][i]]);
        dp[u] = max(dp[u], dp[e[u][i]]);
    }
    sort(v.begin(), v.end());
    dp[u] = max(dp[u], v[v.size() - 1] + v[v.size() - 2] + 1);
    l[u] = v[v.size() - 1] + 1;
}

int main() {
    int i, j, l, r, q, d, n, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (i = 2; i < N; ++i)
    if (v[i].size() == 0)
        for (j = i; j < N; j += i)
            v[j].push_back(i);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a;
        for (j = 0; j < v[a].size(); ++j)
            sp[v[a][j]].push_back(i);
    }
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0);
    for (i = 1; i <= n; ++i)
        e[i].clear();
    int ans = 0;
    for (i = 2; i < N; ++i)
    if (sp[i].size() > ans) {
        for (j = 0; j < sp[i].size(); ++j)
            is[sp[i][j]] = true, use[sp[i][j]] = false;
        for (j = 0; j < sp[i].size(); ++j)
        if (is[p[sp[i][j]]]) {
            e[p[sp[i][j]]].push_back(sp[i][j]);
            e[sp[i][j]].push_back(p[sp[i][j]]);
        }
        for (j = 0; j < sp[i].size(); ++j)
        if (!use[sp[i][j]]) {
            dfs1(sp[i][j], 0);
            ans = max(ans, dp[sp[i][j]]);
        }
        for (j = 0; j < sp[i].size(); ++j) {
            is[sp[i][j]] = false;
            e[sp[i][j]].clear();
        }
    }
    cout << ans << endl;
}