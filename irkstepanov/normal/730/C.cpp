#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;

const int inf = 1e9;

struct shop
{
	ll cnt;
	ll cost;
	int city;
	bool operator<(const shop& other) const
	{
		return cost < other.cost;
	}
};

int n;
vector<vector<int> > g;
vector<int> order, dist;

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		order.pb(v);
		for (int to : g[v]) {
			if (dist[to] == inf) {
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}
}

vector<shop> sorted;

ll solve(ll cnt, int d)
{
	ll ans = 0;
	for (int i = 0; i < sz(sorted); ++i) {
		if (dist[sorted[i].city] <= d) {
			if (cnt >= sorted[i].cnt) {
				ans += sorted[i].cnt * sorted[i].cost;
				cnt -= sorted[i].cnt;
			} else {
				ans += cnt * sorted[i].cost;
				cnt = 0;
			}
		}
	}
	if (cnt != 0) {
		return ll(1e18);
	} else {
		return ans;
	}
}

int main()
{

	//ifstream cin("input.txt");

	cin >> n;
	int m;
	cin >> m;

	g.resize(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	int s;
	cin >> s;

	while (s--) {
		int c, k, p;
		cin >> c >> k >> p;
		--c;
		sorted.pb({k, p, c});
	}

	sort(all(sorted));

	int q;
	cin >> q;

	while (q--) {
		int city;
		ll cnt;
		ll cost;
		cin >> city >> cnt >> cost;
		--city;
		order.clear();
		dist = vector<int>(n, inf);
		bfs(city);
		int lf = 0, rg = n - 1;
		while (rg - lf > 1) {
			int md = (lf + rg) >> 1;
			ll val = solve(cnt, md);
			if (val <= cost) {
				rg = md;
			} else {
				lf = md;
			}
		}
		ll val = solve(cnt, lf);
		if (val <= cost) {
			cout << lf << "\n";
		} else {
			val = solve(cnt, rg);
			if (val <= cost) {
				cout << rg << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}

}