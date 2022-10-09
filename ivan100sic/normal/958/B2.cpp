#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
set<pair<int, int>> e[100005];
set<pair<int, int>> pq;

void dodaj_granu(int u, int v, int w) {
	if (e[u].size() == 1)
		pq.erase({e[u].begin()->second, u});
	if (e[v].size() == 1)
		pq.erase({e[v].begin()->second, v});

	e[u].insert({v, w});
	e[v].insert({u, w});

	if (e[u].size() == 1)
		pq.insert({e[u].begin()->second, u});
	if (e[v].size() == 1)
		pq.insert({e[v].begin()->second, v});
}

int skini_granu(int u, int v) {
	if (e[u].size() == 1)
		pq.erase({e[u].begin()->second, u});
	if (e[v].size() == 1)
		pq.erase({e[v].begin()->second, v});

	int w = e[u].lower_bound({v, -1})->second;
	e[u].erase(e[u].lower_bound({v, -1}));
	e[v].erase(e[v].lower_bound({u, -1}));

	if (e[u].size() == 1)
		pq.insert({e[u].begin()->second, u});
	if (e[v].size() == 1)
		pq.insert({e[v].begin()->second, v});

	return w;
}

int sol[100005];

void sabij(int i) {
	if (e[i].size() == 2) {
		int j = e[i].begin()->first;
		int k = next(e[i].begin())->first;
		int wij = skini_granu(i, j);
		int wik = skini_granu(i, k);
		dodaj_granu(j, k, wij + wik);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		dodaj_granu(u, v, 1);
	}

	for (int i=1; i<=n; i++)
		sabij(i);

	int t = n;
	fill(sol+pq.size(), sol+n+1, n);
	while (pq.size() > 2) {
		int x = pq.begin()->second;
		int y = e[x].begin()->first;
		int wxy = skini_granu(x, y);
		t -= wxy;
		sol[pq.size()] = t;
		sabij(y);
	}
	sol[1] = 1;
	for (int i=1; i<=n; i++)
		cout << sol[i] << " \n"[i == n];
}