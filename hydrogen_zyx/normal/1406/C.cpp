#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int vis[400000];
int sub[400000];
vector<int> g[400000];
int mmaxx;
int p;
int n;

int dfs(int u, int fa, bool gg) {
    sub[u] = 1;
    int mmax = 0;
    for (auto x : g[u]) {
        if (x == fa) continue;
        int ss = dfs(x, u, gg);
        sub[u] += ss;
        mmax = max(mmax, ss);
    }
    mmax = max(mmax, n - sub[u]);
    if (gg && mmax < mmaxx) {
        mmaxx = mmax;
        p = u;
    }
    return sub[u];
}

int ddfs(int u, int fa) {
    if (g[u].size() == 1) return u;
    int mmax = 0;
    for (auto x : g[u]) {
        if (x == fa) continue;
        mmax = max(mmax, sub[x]);
    }
    for (auto x : g[u]) {
        if (x == fa) continue;

        if (sub[x] == mmax) {
            return ddfs(x, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            }
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        mmaxx = 0x3f3f3f3f;
        dfs(1, -1, 1);
        dfs(p, -1, 0);
        int d = ddfs(p, -1);
        cout << d << ' ' << g[d][0] << endl;
        cout << d << ' ' << p << endl;
    }
}