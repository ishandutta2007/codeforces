#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

vector<vector<int> > g;
vector<int> subtree;
vector<bool> used;
vector<int> met;
int n;
ll ans = 0;
int timer = 0;
vector<int> parent;

void dfs1(int v) {
    met[v] = timer;
    subtree[v] = 1;
    for (int to : g[v]) {
        if (used[to] || met[to] == timer) {
            continue;
        }
        parent[to] = v;
        dfs1(to);
        subtree[v] += subtree[to];
    }
}

void dfs2(int v, int p, int depth, vector<int>& res) {
    while (depth >= sz(res)) {
        res.pb(0);
    }
    ++res[depth];
    for (int to : g[v]) {
        if (used[to] || to == p) {
            continue;
        }
        dfs2(to, v, depth + 1, res);
    }
}

void solve(int v) {
    ++timer;
    parent[v] = -1;
    dfs1(v);
    int curr = v;
    while (true) {
        bool go = false;
        for (int to : g[curr]) {
            if (parent[curr] == to || used[to]) {
                continue;
            }
            if (2 * subtree[to] >= subtree[v]) {
                curr = to;
                go = true;
                break;
            }
        }
        if (!go) {
            break;
        }
    }
    int root = curr;
    used[root] = true;
    vector<vector<int> > vct;
    for (int to : g[root]) {
        if (used[to]) {
            continue;
        }
        vector<int> t;
        dfs2(to, root, 1, t);
        vct.pb(t);
    }
    vector<int> sum;
    for (int i = 0; i < sz(vct); ++i) {
        while (sz(sum) < sz(vct[i])) {
            sum.pb(0);
        }
        for (int j = 0; j < sz(vct[i]); ++j) {
            sum[j] += vct[i][j];
        }
    }
    ll res = 0;
    for (int j = 0; j < sz(sum); ++j) {
        //cout << root + 1 << " " << j << " " << sum[j] << endl;
        res += ll(sum[j]) * ((j + 1) / 2);
    }
    ll res1 = 0;
    for (int j = 0; j < sz(sum); ++j) {
        res1 += ll(sum[j]) * (j / 2);
    }
    int cnt = 0;
    for (int i = 0; i < sz(sum); ++i) {
        cnt += sum[i];
    }
    ans += res;
    for (int i = 0; i < sz(vct); ++i) {
        for (int j = 0; j < sz(vct[i]); ++j) {
            sum[j] -= vct[i][j];
            res -= ll(vct[i][j]) * ((j + 1) / 2);
            res1 -= ll(vct[i][j]) * (j / 2);
            cnt -= vct[i][j];
        }
        for (int j = 0; j < sz(vct[i]); ++j) {
            if (j % 2 == 0) {
                ans += ll(vct[i][j]) * ((j + 1) / 2) * cnt + ll(res) * vct[i][j];
            } else {
                //cout << vct[i][j] << " " << cnt << " " << res1 << endl;
                ans += ll(vct[i][j]) * ((j + 1) / 2) * cnt + ll(res1) * vct[i][j];
            }
        }
    }
    //cout << "!" << root + 1 << " " << ans << endl;
    for (int to : g[root]) {
        if (!used[to]) {
            solve(to);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    g.resize(n);
    met.assign(n, 0);
    parent.resize(n);
    subtree.resize(n);
    used.assign(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    solve(0);
    cout << ans << "\n";
    
}