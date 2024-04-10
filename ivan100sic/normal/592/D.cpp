#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
basic_string<int> e[200005];
int q[200005], d[200005], edges;

int dfs(int x, int p) {
	int f = q[x];
	for (int y : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x] + 1;
		f |= dfs(y, x);
	}
	edges += f;
	return f;
}

int najd() {
	int y = 0;
	for (int i=1; i<=n; i++) {
		if (q[i] && d[i] >= d[y]) {
			y = i;
		}
	}
	return y;
}

set<int> diam_set(int x) {
	edges = 0;
	d[x] = 0;
	dfs(x, x);
	set<int> s;
	int w = -1;
	for (int i=1; i<=n; i++) {
		if (q[i]) {
			if (d[i] > w) {
				w = d[i];
				s = {i};
			} else if (d[i] == w) {
				s.insert(i);
			}
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	int o = 0;
	while (k--) {
		cin >> o;
		q[o] = 1;
	}

	auto s1 = diam_set(o);
	int sol = edges - 1;
	int p1 = *s1.begin();
	auto s2 = diam_set(p1);
	int p2 = *s2.begin();
	s1.insert(s2.begin(), s2.end());
	cout << *s1.begin() << '\n';
	cout << 2*sol - d[p2] << '\n';
}