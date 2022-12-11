#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

vector<ll> dist;

const ll inf = 1e18;

struct comp
{
    bool operator()(int a, int b)
    {
        if (dist[a] != dist[b]) {
            return dist[a] < dist[b];
        }
        return a < b;
    }
};

struct edge
{
    int to;
    ll cost;
};

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<edge> > g(n);
    vector<int> p(n);
    p[0] = -1;

    while (m--) {
        int u, v;
        ll cost;
        cin >> u >> v >> cost;
        --u, --v;
        g[u].pb({v, cost});
        g[v].pb({u, cost});
    }

    dist.assign(n, inf);
    dist[0] = 0;
    set<int, comp> q;
    q.insert(0);

    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (edge& e : g[v]) {
            ll relax = dist[v] + e.cost;
            if (dist[e.to] > relax) {
                q.erase(e.to);
                dist[e.to] = relax;
                q.insert(e.to);
                p[e.to] = v;
            }
        }
    }

    if (dist.back() == inf) {
        cout << "-1\n";
        return 0;
    }

    vector<int> ans;
    int curr = n - 1;
    while (curr != -1) {
        ans.pb(curr);
        curr = p[curr];
    }
    reverse(all(ans));
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}