#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

vector<vector<int> > g;
ll k;
vector<ll> cost;
vector<vector<int> > dist;

void dfs1(int v, int p, int s, int d) {
    dist[s][v] = d;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs1(to, v, s, d + 1);
    }
}

vector<ll> dp;
vector<int> parent;
vector<int> tin, tout;
int timer = 0;

void dfs2(int v, int p) {
    tin[v] = timer++;
    parent[v] = p;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs2(to, v);
    }
    tout[v] = timer++;
}

bool ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

void getAll(int v, vector<int>& vct) {
    vct.pb(v);
    for (int to : g[v]) {
        if (to == parent[v]) {
            continue;
        }
        getAll(to, vct);
    }
}

vector<vector<int> > closest, nx;
const ll inf = 1e18;
vector<ll> tmp;
vector<int> best;

void dfs3(int v) {
    vector<int> vct;
    getAll(v, vct);
    int children = 0;
    for (int to : g[v]) {
        if (to == parent[v]) {
            continue;
        }
        ++children;
        dfs3(to);
    }

    dp[v] = inf;
    for (int c : vct) {
        ll sum = k;
        int d = dist[c][v];
        for (int i = 1; i <= d; ++i) {
            sum += cost[i];
        }
        for (int j = sz(vct) - 1; j >= 0; --j) {
            int u = vct[j];
            if (ancestor(u, c)) {
                continue;
            }
            tmp[u] = cost[dist[c][u]];
            for (int to : g[u]) {
                if (to == parent[u]) {
                    continue;
                }
                tmp[u] += tmp[to];
            }
            tmp[u] = min(tmp[u], dp[u]);
        }
        queue<int> q;
        int curr = c;
        while (curr != v) {
            q.push(curr);
            curr = parent[curr];
        }
        q.push(v);
        vector<int> traversed;
        vector<int> nxt;
        while (!q.empty()) {
            int u = q.front();
            traversed.pb(u);
            q.pop();
            for (int to : g[u]) {
                if (to == parent[u] || ancestor(to, c)) {
                    continue;
                }
                if (tmp[to] < dp[to]) {
                    q.push(to);
                    sum += cost[dist[to][c]];
                } else {
                    sum += dp[to];
                    nxt.pb(to);
                }
            }
        }
        if (sum < dp[v]) {
            dp[v] = sum;
            closest[v] = traversed;
            nx[v] = nxt;
            best[v] = c;
        }
    }

    if (children == 0) assert(dp[v] == k);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n >> k;
    cost.resize(n);
    for (int i = 1; i <= n - 1; ++i) {
        cin >> cost[i];
    }

    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dist = vector<vector<int> >(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        dfs1(i, -1, i, 0);
    }

    parent.resize(n);
    tin.resize(n);
    tout.resize(n);
    dp.resize(n);
    tmp.resize(n);
    closest.resize(n);
    best.resize(n);
    nx.resize(n);

    dfs2(0, -1);
    dfs3(0);
    cout << dp[0] << "\n";
    queue<int> q;
    q.push(0);
    vector<int> ans(n);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int c = best[v];
        for (int x : closest[v]) {
            ans[x] = c;
        }
        for (int x : nx[v]) {
            q.push(x);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";

}