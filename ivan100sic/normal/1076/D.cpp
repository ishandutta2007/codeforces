#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int u[300005], v[300005], p[300005];
ll w[300005], d[300005];

int n, m, k;
basic_string<int> e[300005], f[300005], sol;
set<int> nedrvo;

void dfs(int x, int& g) {
	if (!g) return;
	for (int i : f[x]) {
		if (g) {
			sol += i;
			g--;
			dfs(x ^ u[i] ^ v[i], g);
		} else {
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		nedrvo.insert(i);
		e[u[i]] += i;
		e[v[i]] += i;
	}

	set<pair<ll, int>> pq;
	fill(d+2, d+n+1, 123123123123123123ll);
	d[1] = 0;
	pq.insert({0, 1});
	while (pq.size()) {
		int x = pq.begin()->second;
		pq.erase(pq.begin());
		for (int i : e[x]) {
			int y = x ^ u[i] ^ v[i];
			int l = w[i];
			if (d[y] > d[x] + l) {
				pq.erase({d[y], y});
				p[y] = i;
				d[y] = d[x] + l;
				pq.insert({d[y], y});
			}
		}
	}

	for (int i=2; i<=n; i++) {
		int j = p[i];
		int par = u[j] ^ v[j] ^ i;
		f[par] += j;
		nedrvo.erase(j);
	}

	dfs(1, k);

	cerr << sol.size() << ' ' << k << '\n';

	while (k > 0) {
		sol += *nedrvo.begin();
		nedrvo.erase(nedrvo.begin());
		k--;
	}

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}