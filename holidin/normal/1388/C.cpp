#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;
vector <int> e[N];
int p[N], sumh[N], h[N], sump[N];
bool good;

void dfs(int u, int pr) {
    sump[u] = p[u];
    sumh[u] = 0;
    if (e[u].size() == 0 || (u != 1 && e[u].size() == 1)) {
        if (abs(h[u]) > p[u] || abs(h[u]) % 2 != p[u] % 2) {
            good = false;
        }
        return;
    }
    for (auto x : e[u])
    if (x != pr) {
        dfs(x, u);
        sump[u] += sump[x];
        sumh[u] += h[x];
    }
    if (abs(h[u]) > sump[u] || abs(sump[u]) % 2 != abs(h[u]) % 2 || sumh[u] - h[u] > p[u] || abs(h[u] - sumh[u]) % 2 != p[u] % 2) {
        good = false;
    }
}


void solve() {
    int n, i, j, k, a, b;
    cin >> n >> k;
    good = true;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0);
    if (good)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}