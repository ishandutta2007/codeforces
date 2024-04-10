#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, L, s, t, k;
int u[10005], v[10005];
ll w[10005];
basic_string<int> blank, e[1005];
ll d[1005];

void dijkstra() {
	fill(d, d+n, 123123123123123123ll);
	d[s] = 0;
	set<pair<ll, int>> pq;
	pq.insert({0, s});
	while (pq.size()) {
		auto [dist, x] = *pq.begin();
		pq.erase(pq.begin());
		for (int i : e[x]) {
			int y = u[i] ^ v[i] ^ x;
			if (d[y] > dist + w[i]) {
				pq.erase({d[y], y});
				d[y] = dist + w[i];
				pq.insert({d[y], y});
			}
		}
	}
}

void popuni(ll x) {
	for (int i=0; i<k; i++)
		w[blank[i]] = x/k + (i<x%k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> L >> s >> t;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		e[u[i]] += i;
		e[v[i]] += i;
		if (w[i] == 0)
			blank += i;
	}
	k = blank.size();

	dijkstra();
	if (d[t] > L) {
		cout << "NO\n";
		return 0;
	}

	ll lo = k, hi = k*1.01e13, o = -1;
	while (lo <= hi) {
		ll mid = (lo+hi) >> 1;
		popuni(mid);
		dijkstra();
		if (d[t] > L) {
			hi = mid - 1;
		} else if (d[t] < L) {
			lo = mid + 1;
		} else {
			o = mid;
			break;
		}
	}

	if (o == -1) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (int i=0; i<m; i++)
		cout << u[i] << ' ' << v[i] << ' ' << w[i] << '\n';
}