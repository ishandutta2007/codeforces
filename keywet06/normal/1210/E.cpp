#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxn = 2e5 + 79, maxk = 5, maxf = 121;

vector<vector<int> > g(maxf, vector<int>(maxf, -1));
map<vector<int>, int> m;
vector<vector<int> > p;

int n, k;

int combine(vector<int> &f, vector<int> &g) {
    vector<int> h(k);
    for (int i = 0; i < k; ++i) h[i] = f[g[i]];
    return m[h];
}

void dfs(int u, vector<int> &good, vector<int> &vis, int &cnt) {
    vis[u] = true;
    cnt++;
    for (int i : good) {
        if (!vis[g[u][i]]) dfs(g[u][i], good, vis, cnt);
        if (!vis[g[i][u]]) dfs(g[i][u], good, vis, cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<int> f(k);
    for (int i = 0; i < k; ++i) f[i] = i;
    do {
        m[f] = p.size();
        p.push_back(f);
    } while (next_permutation(f.begin(), f.end()));
    int kf = p.size();
    for (int i = 0; i < kf; ++i)
        for (int j = 0; j < kf; ++j) g[i][j] = combine(p[i], p[j]);
    vector<int> last(kf, -1), vis(kf);
    ll ans = 0;
    for (int r = 0; r < n; ++r) {
        for (int i = 0; i < kf; ++i) vis[i] = 0;
        vis[0] = 1;
        vector<int> nw(k), good{0};
        for (int i = 0; i < k; ++i) cin >> nw[i], nw[i]--;
        last[m[nw]] = r;
        vector<pair<int, int> > v;
        for (int i = 0; i < kf; ++i)
            if (last[i] != -1) v.push_back({last[i], i});
        sort(v.begin(), v.end(), greater<pair<int, int> >());
        int cnt = 1;
        v.push_back({-1, -1});
        for (int i = 0; i < v.size() - 1; ++i) {
            if (!vis[v[i].second]) {
                good.push_back(v[i].second);
                dfs(v[i].second, good, vis, cnt);
            }
            ans += (v[i].first - v[i + 1].first) * 1ll * cnt;
        }
    }
    cout << ans << "\n";
    return 0;
}