#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int curr;
queue<int> q;
vector<vector<int> > g;
vector<bool> alive;
vector<set<int> > deg;
int k;

void f() {
    while (!q.empty()) {
        --curr;
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            deg[to].erase(v);
            if (sz(deg[to]) < k && alive[to]) {
                alive[to] = false;
                q.push(to);
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m >> k;

    vector<pii> edges(m);
    g.resize(n);
    deg.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[i] = {u, v};
        deg[u].insert(v);
        deg[v].insert(u);
        g[u].pb(v);
        g[v].pb(u);
    }

    alive.assign(n, true);
    for (int i = 0; i < n; ++i) {
        if (sz(deg[i]) < k) {
            q.push(i);
            alive[i] = false;
        }
    }

    curr = n;
    f();

    vector<int> ans(m);
    ans[m - 1] = curr;
    //cout << deg[0] << " " << deg[1] << " " << deg[2] << endl;
    for (int i = m - 1; i >= 1; --i) {
        /*for (int j = 0; j < n; ++j) {
            if (alive[j]) cout << "!" << j + 1 << " " << deg[j] << "\n";
        }
        cout << "\n";*/
        int u = edges[i].first, v = edges[i].second;
        if (!alive[u] || !alive[v]) {
            ans[i - 1] = curr;
            continue;
        }
        deg[u].erase(v);
        deg[v].erase(u);
        if (sz(deg[u]) < k) {
            q.push(u);
            alive[u] = false;
        }
        if (sz(deg[v]) < k) {
            q.push(v);
            alive[v] = false;
        }
        f();
        ans[i - 1] = curr;
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }

}