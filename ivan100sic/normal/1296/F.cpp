// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[5005];
int d[5005], p[5005], w[5005];

void dfs(int x) {
	for (int y : e[x]) {
		if (y == p[x])
			continue;
		p[y] = x;
		d[y] = d[x] + 1;
		dfs(y);
	}
}

template<class T>
void vis(int a, int b, T f) {
	while (a != b) {
		if (d[a] > d[b])
			swap(a, b);
		f(b);
		b = p[b];
	}
}

pair<int, int> g[5005];
struct upit {
	int a, b, c;
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1, u, v; i<n; i++)
		cin >> u >> v, e[u] += v, e[v] += u, g[i] = {u, v};

	dfs(1);

	int q;
	cin >> q;
	vector<upit> v(q);

	fill(w+2, w+n+1, 1);

	for (auto& [a, b, c] : v) {
		cin >> a >> b >> c;
		vis(a, b, [&](int x) {
			w[x] = max(w[x], c);
		});
	}

	for (int i=1; i<n; i++) {
		auto [a, b] = g[i];
	}

	for (auto& [a, b, c] : v) {
		int mn = 1e9;
		vis(a, b, [&](int x) {
			mn = min(mn, w[x]);
		});
		if (mn != c) {
			cout << "-1\n";
			return 0;
		}
	}

	for (int i=1; i<n; i++) {
		auto [a, b] = g[i];
		cout << w[d[a] < d[b] ? b : a] << " \n"[i == n-1];
	}
}