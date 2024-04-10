#include <bits/stdc++.h>

using namespace std;
int n, k;
const int maxN = 105;
int f[maxN][maxN];
vector<int> g[maxN];
int p[maxN];
void dfs(int v, int t) {
    for (int to : g[v]) {
        if (to == t) continue;
        p[to] = v;
        dfs(to, v);
    }
}
bool was[maxN];
bool go(int c, int par, vector<int>& ans) {
    if (!k) {
        return false;
    }
    k--;
    ans.emplace_back(c);
    for (int to : g[c]) {
        if (to == par) continue;
        if (go(to, c, ans)) {
            ans.emplace_back(c);
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            for (int j = 1; j <= n; j++) {
                f[i][j] = n + 100;
            }
            f[i][i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            g[x].emplace_back(i);
            g[i].emplace_back(x);
            f[i][x] = f[x][i] = 1;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        int best = -1e9;
        int x = -1;
        int y = -1;
        for (int i = 1; i <= 1; i++) {
            for (int j = 1; j <= n; j++) {
                if (best < f[i][j]) {
                    x = i;
                    y = j;
                    best = f[i][j];
                }
            }
        }
        p[x] = -1;
        dfs(x, -1);
        vector<int> ans;
        if (best >= k - 1) {
            while (y != -1) {
                ans.emplace_back(y);
                y = p[y];
            }
            reverse(ans.begin(), ans.end());
            assert(ans.size() >= k);
            ans.resize(k);
        }
        else {
            vector<int> path;
            int ty = y;
            while (ty != -1) {
                path.emplace_back(ty);
                ty = p[ty];
            }
            reverse(path.begin(), path.end());
            memset(was, 0, sizeof was);
            for (int i = 0; i < path.size(); i++) {
                k--;
                ans.emplace_back(path[i]);
                if (i == path.size() - 1) {
                    assert(k == 0);
                }
                for (int c : g[path[i]]) {
                    if (i > 0 && c == path[i - 1]) continue;
                    if (i + 1 < path.size() && c == path[i + 1]) continue;
                    k -= (path.size() - i - 1);
                    if (go(c, path[i], ans)) {
                        ans.emplace_back(path[i]);
                    }
                    k += (path.size() - i - 1);
                }
            }
        }
        cout << ans.size() - 1 << '\n';
        for (int v : ans) cout << v << " ";
        cout << '\n';
    }
    return 0;
}