#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 100, inf = 1e9;
const int base = 1e9 + 7;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define ld long double

int f[maxn];
vector<int> g[maxn];

void dfs(int v, int p = -1) {
    int f_p = -1;
    if (p != -1)
        f_p = f[p];
    int curEmpty = 1;
    for (int to:g[v]) {
        if (to == p) continue;
        while (curEmpty == f_p || curEmpty == f[v])
            curEmpty++;
        f[to] = curEmpty;
        dfs(to, v);
        curEmpty++;
    }
}

int main() {
    int n;
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;

    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    f[0] = 1;
    dfs(0);
    int mx = 0;
    for (int i = 0; i < n ; i++)
        mx = max(mx, f[i]);

    cout << mx << "\n";
    for (int i = 0; i < n; i++)
        cout << f[i] << ' ';
    return 0;
}