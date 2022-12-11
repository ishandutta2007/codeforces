#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const ll inf = 1e18;

struct edge
{
	int from, to;
	ll w, p;
	ll delta;
	int id;
};

vector<edge> edges;
vector<vector<int> > g;
vector<ll> sum;
bool ok = true;
ll ans = 0;

void dfs1(int v)
{
	sum[v] = 0;
	for (int e : g[v]) {
		dfs1(edges[e].to);
		ll a = min(edges[e].p, min(edges[e].w - 1, edges[e].p - sum[edges[e].to]));
		sum[v] += sum[edges[e].to];
		if (a < 0) {
			ok = false;
			return;
		}
		edges[e].w -= a;
		edges[e].p -= a;
		edges[e].delta = a;
		ans += a;
		sum[v] += edges[e].w;
	}
}

ll dfs2(int v, ll r)
{
	ll spent = 0;
	for (int e : g[v]) {
		ll val = min(edges[e].delta, r);
		edges[e].w += val;
		edges[e].p += val;
		r -= val;
		spent += val;
		ll x = dfs2(edges[e].to, min(r, edges[e].p - sum[edges[e].to]));
		r -= x;
		spent += x;
	}
	return spent;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		ll w, p;
		cin >> u >> v >> w >> p;
		--u, --v;
		edges.pb({u, v, w, p, 0, i});
		g[u].pb(i);
	}

	sum.resize(n);
	dfs1(0);

	if (!ok) {
		cout << "-1\n";
		return 0;
	}

	dfs2(0, inf);
	cout << n << "\n";
	for (int i = 0; i < sz(edges); ++i) {
		cout << edges[i].from + 1 << " " << edges[i].to + 1 << " " << edges[i].w << " " << edges[i].p << "\n";
	}

}