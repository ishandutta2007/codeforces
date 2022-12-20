#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 2e2 + 1;
vector <int> e[N];
bool use[N];
int deep[N], h[N], ish[N], nz[N], cnt = 0, num = 0;
vector <pair<int, int> > t, ans;

void dfs0(int u, int pr) {
    use[u] = 1;
    h[u] = deep[u];
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        if (use[e[u][i]]) {
            if (deep[e[u][i]] < h[u]) {
                h[u] = deep[e[u][i]];
                nz[u] = e[u][i];
                ish[u] = u;
            }
        } else {
            deep[e[u][i]] = deep[u] + 1;
            dfs0(e[u][i], u);
            t.push_back({e[u][i], u});
            if (h[e[u][i]] < h[u]) {
                h[u] = h[e[u][i]];
                ish[u] = ish[e[u][i]];
                nz[u] = nz[e[u][i]];
            }
        }
    }
}

int dfs1(int u, int pr) {
    int hg = deep[u];
    for (int i = 0; i < e[u].size(); ++i)
    if (deep[e[u][i]] == deep[u] + 1)
        hg = min(hg, dfs1(e[u][i], u));
    if (hg == deep[u] && u != 1) {
        ++cnt;
        hg = h[u];;
        t.push_back({nz[u], ish[u]});
    }
    return hg;
}

int main() {
    int i, j, n, k, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= k; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        ans.push_back({a, b});
    }
    while (clock() < 100) {
        for (i = 1; i <= n; ++i) {
            random_shuffle(e[i].begin(), e[i].end());
            use[i] = 0;
        }
        ++num;
        t.clear();
        dfs0(1, 0);
        cnt = n - 1;
        dfs1(1, 0);
        if (t.size() < ans.size())
            ans = t;
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << endl;
}