#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

struct edge
{
    int from, to;
    ll cost;
};

vector<vector<edge> > g;
vector<ll> a;
vector<int> parent;
vector<ll> max_dist;

void dfs(int v, int p)
{
    parent[v] = p;
    for (edge& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        max_dist[e.to] = max((ll)0, e.cost + max_dist[v]);
        dfs(e.to, v);
    }
}

vector<char> used;

void dfs2(int v, int p)
{
    used[v] = true;
    for (edge& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        if (!used[e.to]) {
            dfs2(e.to, v);
        }
    }
}

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    parent.resize(n);
    g.resize(n), a.resize(n);

    fori {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int v;
        cin >> v;
        ll cost;
        cin >> cost;
        --v;
        g[i + 1].pb({i + 1, v, cost});
        g[v].pb({v, i + 1, cost});
    }

    max_dist.resize(n);
    dfs(0, -1);

    used.assign(n, false);
    fori {
        if (a[i] < max_dist[i]) {
            //cout << i << " " << a[i] << " " << max_dist[i] << "\n";
            dfs2(i, parent[i]);
        }
    }

    int ans = 0;
    fori {
        if (used[i]) {
            ++ans;
            //cout << i << " ";
        }
    }

    cout << ans << "\n";

}