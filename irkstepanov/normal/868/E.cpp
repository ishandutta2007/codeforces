// MIPT Shock Content (place 19)

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

const ll inf = 1e18;

struct edge {
    int from, to;
    ll cost;
    int id;
};

vector<vector<edge> > g;
vector<char> used;
int n, k;
vector<vector<ll> > dp;
vector<vector<ll> > dist;

/*ll dfs(int v, int p) {
    ll ans = 0;
    int bestId = -1;
    for (edge& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        ll val = dfs(e.to, v);
        if (!used[e.id]) {
            val += e.cost;
        }
        if (val > ans) {
            ans = val;
            bestId = e.id;
        }
    }
    if (bestId != -1) {
        used[bestId] = true;
    }
    return ans;
}*/

void dfs(int v, int p, int root, ll curr) {
    dist[root][v] = curr;
    for (edge& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        dfs(e.to, v, root, curr + e.cost);
    }
}

vector<int> subtreeId;
int cnt = -1;

void dfsSubtree(int v, int p) {
    subtreeId[v] = cnt;
    for (edge& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        if (v == p) {
            ++cnt;
        }
        dfsSubtree(e.to, v);
    }
}

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].pb({u, v, c, i});
        g[v].pb({v, u, c, i});
    }

    dist = vector<vector<ll> >(n, vector<ll>(n));
    for (int v = 0; v < n; ++v) {
        dfs(v, v, v, 0);
    }

    int start;
    cin >> start;
    --start;

    cin >> k;
    vector<int> criminals(k);
    for (int i = 0; i < k; ++i) {
        cin >> criminals[i];
        --criminals[i];
    }

    dp = vector<vector<ll> >(n, vector<ll>(k + 1));
    for (int v = 0; v < n; ++v) {
        if (sz(g[v]) == 1) {
            dp[v][0] = 0;
        }
    }

    for (int j = 1; j <= k; ++j) {
        for (int v = 0; v < n; ++v) {
            if (sz(g[v]) == 1) {
                ll lf = 0, rg = inf;
                while (rg - lf > 1) {
                    ll md = (lf + rg) >> 1;
                    int maxSum = 0;
                    for (int u = 0; u < n; ++u) {
                        if (u == v || sz(g[u]) != 1) {
                            continue;
                        }
                        int maxx = -1;
                        for (int i = 0; i < j; ++i) {
                            if (dp[u][i] + dist[v][u] >= md) {
                                maxx = i;
                                break;
                            }
                        }
                        if (maxx >= 0) {
                            maxSum += j - maxx;
                        }
                    }
                    if (maxSum >= j) {
                        lf = md;
                    } else {
                        rg = md;
                    }
                }
                dp[v][j] = lf;
            }
        }
    }

    /*for (int v = 0; v < n; ++v) {
        if (sz(g[v]) == 1) {
            cout << v + 1 << ": ";
            for (int j = 0; j <= k; ++j) {
                cout << dp[v][j] << " ";
            }
            cout << "\n";
        }
    }*/

    if (sz(g[start]) == 1) {
        cout << dp[start][k] << "\n";
        return 0;
    }

    subtreeId.resize(n);
    dfsSubtree(start, start);

    vector<int> num(cnt + 1);
    for (int i = 0; i < k; ++i) {
        ++num[subtreeId[criminals[i]]];
        //cout << "!" << subtreeId[criminals[i]] << "\n";
    }

    ll lf = 0, rg = inf;
    //ll lf = 10, rg = 12;
    while (rg - lf > 1) {
        ll md = (lf + rg) >> 1;
        vector<int> total(cnt + 1);
        for (int u = 0; u < n; ++u) {
            if (u == start || sz(g[u]) != 1) {
                continue;
            }
            int maxx = -1;
            for (int i = 0; i <= k; ++i) {
                if (dp[u][i] + dist[start][u] >= md) {
                    maxx = i;
                    break;
                }
            }
            //cout << u + 1 << " " << maxx << "\n";
            if (maxx >= 0) {
                total[subtreeId[u]] += k - maxx;
            }
        }
        bool ok = true;
        for (int i = 0; i <= cnt; ++i) {
            if (total[i] < num[i]) {
                ok = false;
            }
        }
        if (ok) {
            lf = md;
        } else {
            rg = md;
        }
    }

    cout << lf << "\n";

}