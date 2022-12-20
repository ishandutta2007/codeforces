#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e5 + 1;
int cnt = 0;
bool flag = 0;
vector <pair<int, int> > e[N];
vector <int> v[N];
vector <pair<pair<int, int>, int> > ans;
int f[N];

int start = 0;

void dfs(int u, int pr) {
    if (e[u].size() == 1) {
        f[u] = u;
        return;
    }
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr) {
        dfs(e[u][i].fi, u);
        v[u].push_back(f[e[u][i].fi]);
        f[u] = f[e[u][i].fi];
    }
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr)
        if (v[u][0] == f[e[u][i].fi])
            v[e[u][i].fi].push_back(v[u][1]);
        else
            v[e[u][i].fi].push_back(v[u][0]);
}

void dfs1(int u, int pr, int xp) {
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr) {
        if (f[e[u][i].fi] == f[u])
            e[u][i].se -= xp;
        int x = -1, y = -1;
        for (int j = 0; j < 3; ++j)
        if (v[u][j] != f[e[u][i].fi]) {
            y = x;
            x = v[u][j];
        }
        ans.push_back({{f[e[u][i].fi], x}, e[u][i].se / 2});
        ans.push_back({{f[e[u][i].fi], y}, e[u][i].se / 2});
        ans.push_back({{x, y}, -e[u][i].se / 2});
        if (f[e[u][i].fi] == f[u])
            dfs1(e[u][i].fi, u, xp + e[u][i].se);
        else
            dfs1(e[u][i].fi, u, e[u][i].se);
    }
}

int main() {
    int i, j, k, n, a, b, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    start = 0;
    for (i = 1; i <= n; ++i)
    if (e[i].size() == 2)
        flag = 1;
    else if (e[i].size() > 1)
            start = i;
    if (flag) {
        cout << "NO";
        exit(0);
    }
    if (n == 2) {
        cout << "YES\n";
        cout << 1 << endl;
        cout << 1 << ' ' << 2 << ' ' << c << "\n";
        return 0;
    }
    dfs(start, 0);
    dfs1(start, 0, 0);
    cout << "YES\n";
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i].fi.fi << ' ' << ans[i].fi.se << ' ' << ans[i].se << "\n";
}