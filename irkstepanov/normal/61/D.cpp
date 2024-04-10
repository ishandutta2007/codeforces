#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct edge {
    int from, to;
    ll cost;
};

vector<vector<edge> > g;

vector<ll> dist;

void dfs(int v, int p) {
    for (edge& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        dist[e.to] = dist[v] + e.cost;
        dfs(e.to, v);
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
    cin >> n;
    g.resize(n);
    ll sum = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ll c;
        cin >> c;
        g[u].pb({u, v, c});
        g[v].pb({v, u, c});
        sum += c * 2;
    }

    dist.assign(n, -1);
    dist[0] = 0;
    dfs(0, 0);

    ll maxx = -1;
    int opt = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > maxx) {
            maxx = dist[i];
            opt = i;
        }
    }

    /*dist.assign(n, -1);
    dist[opt] = 0;
    dfs(opt, opt);

    maxx = -1;
    for (int i = 0; i < n; ++i) {
        maxx = max(maxx, dist[i]);
    }
    cout << maxx << endl;*/

    cout << sum - maxx << endl;

}