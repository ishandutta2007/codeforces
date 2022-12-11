#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct edge
{
    int from, to;
    ll cost;
};

vector<vector<edge> > g;
vector<ll> dp1, dp2;
int k;

struct child
{
    ll x1, x2;
    ll e;
    bool operator<(const child& other) const
    {
        return x1 + e > other.x1 + other.e;
    }
};

void dfs(int v, int p)
{
    if (sz(g[v]) == 1 && g[v][0].to == p) {
        dp1[v] = dp2[v] = 0;
        return;
    }
    vector<child> a;
    for (edge& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        dfs(e.to, v);
        a.pb({dp1[e.to], dp2[e.to], e.cost});
    }
    sort(all(a));
    int s = min(sz(a), k - 1);
    ll sum = 0;
    for (int i = 0; i < s; ++i) {
        sum += a[i].x1 + a[i].e;
    }
    dp1[v] = dp2[v] = sum;

    s = min(sz(a), k);
    sum = 0;
    for (int i = 0; i < s; ++i) {
        sum += a[i].x1 + a[i].e;
    }
    for (int i = 0; i < sz(a); ++i) {
        if (i < s) {
            dp2[v] = max(dp2[v], sum - a[i].x1 + a[i].x2);
        } else {
            dp2[v] = max(dp2[v], sum - (a[s - 1].x1 + a[s - 1].e) + (a[i].x2 + a[i].e));
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> k;

    g.resize(n);
    dp1.resize(n);
    dp2.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ll cost;
        cin >> u >> v >> cost;
        g[u].pb({u, v, cost});
        g[v].pb({v, u, cost});
    }

    dfs(0, 0);

    cout << dp2[0] << "\n";

}