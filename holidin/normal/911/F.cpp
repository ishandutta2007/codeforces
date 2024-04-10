#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 6e5 + 1;

vector <int> e[N], diam;
vector <pair<int, int> > v;
int c[N], dans, type[N];
long long ans = 0;
bool is = 0;

void dfs(int u, int pr, int d) {
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        dfs(e[u][i], u, d + 1);
    if (d > dans) {
        ans = u;
        dans = d;
    }
}

void dfs1(int u, int pr, int d) {
    if (!is)
        diam.push_back(u);
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        dfs1(e[u][i], u, d + 1);
    if (d == dans)
        is = true;
    if (!is)
        diam.resize(diam.size() - 1);
}

int main() {
    int i, j, k, n, l, r, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0, 0);
    dans = 0;
    dfs(ans, 0, 0);
    dfs1(ans, 0, 0);
    for (i = 0; i < diam.size(); ++i) {
        c[diam[i]] = 2;
        v.push_back({diam[i], max(i, (int) diam.size() - i - 1)});
        if (i < diam.size() / 2)
            type[diam[i]] = diam[diam.size() - 1];
        else
            type[diam[i]] = diam[0];
    }
    ans = 0;
    for (i = 0; i < v.size(); ++i) {
        if (c[v[i].fi] == 1)
            ans += v[i].se;
        int u = v[i].fi;
        for (j = 0; j < e[u].size(); ++j)
        if (c[e[u][j]] == 0) {
            c[e[u][j]] = 1;
            type[e[u][j]] = type[u];
            v.push_back({e[u][j], v[i].se + 1});
        }
    }
    long long kk = diam.size();
    ans += (kk * (kk - 1)) / 2;
    cout << ans << endl;
    for (i = v.size() - 1; c[v[i].fi] == 1; --i)
        cout << type[v[i].fi] << ' '  << v[i].fi << ' ' << v[i].fi << "\n";
    for (i = diam.size() - 1; i > 0; --i)
        cout << diam[0] << ' ' << diam[i] << ' ' << diam[i] << "\n";
}