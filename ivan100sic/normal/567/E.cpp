#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, s, t;
int u[100005], v[100005], w[100005], ans[100005];
basic_string<int> e[100005], f[100005], g[100005];
ll ds[100005], dt[100005];

template<class T>
void dijk(int x, T e, int* u, ll* d) {
	set<pair<ll, int>> pq;
	fill(d+1, d+n+1, 1e18);
	d[x] = 0;
	pq.insert({d[x], x});
	while (pq.size()) {
		auto [dx, x] = *pq.begin();
		pq.erase(pq.begin());
		for (int i : e[x]) {
			int y = u[i], z = w[i];
			if (d[y] > dx + z) {
				pq.erase({d[y], y});
				d[y] = dx + z;
				pq.insert({d[y], y});
			}
		}
	}
}

int idx[100005], low[100005], dfst;
bool inst[100005];

void dfs(int x, int pi) {
	low[x] = idx[x] = ++dfst;
	inst[x] = 1;
	for (int i : g[x]) {
		if (i == pi)
			continue;
		int y = u[i] ^ v[i] ^ x;
		if (idx[y] == 0) {
			dfs(y, i);
			low[x] = min(low[x], low[y]);
		} else if (inst[y] == 1) {
			low[x] = min(low[x], idx[y]);
		}
	}
	inst[x] = 0;
	if (idx[x] == low[x] && pi != -1)
		ans[pi] = -2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s >> t;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		e[u[i]] += i;
		f[v[i]] += i;
	}

	dijk(s, e, v, ds);
	dijk(t, f, u, dt);

	ll sp = ds[t];

	for (int i=0; i<m; i++) {
		ll cw = ds[u[i]] + w[i] + dt[v[i]];
		if (cw == sp) {
			g[u[i]] += i;
			g[v[i]] += i;
			ans[i] = -3;
		} else if (cw - sp + 1 < w[i]) {
			ans[i] = cw - sp + 1;
		} else {
			ans[i] = -1;
		}
	}

	dfs(s, -1);

	for (int i=0; i<m; i++) {
		if (ans[i] > 0) {
			cout << "CAN " << ans[i] << '\n';
		} else if (ans[i] == -1) {
			cout << "NO\n";
		} else if (ans[i] == -3) {
			if (w[i] == 1) {
				cout << "NO\n";
			} else {
				cout << "CAN 1" << '\n';
			}
		} else {
			cout << "YES\n";
		}
	}
}