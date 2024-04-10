#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[1005];
bool v[1005];
int d[1005], pr[1005];

void dfs1(int x, int p, int& xmax) {
	v[x] = 1;
	if (d[x] > d[xmax])
		xmax = x;
	for (int y : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x] + 1;
		pr[y] = x;
		dfs1(y, x, xmax);
	}
}

int naj(int x) {
	d[x] = 0;
	pr[x] = -1;
	dfs1(x, x, x);
	return x;
}

pair<int, int> find_center(int x) {
	int x1 = naj(x);
	int x2 = naj(x1);
	int c = x2;
	for (int i=0; i<d[x2]/2; i++)
		c = pr[c]; // prc hehe
	return {(d[x2]+1) / 2 * -1, c};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	basic_string<pair<int, int>> cc, sol;
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			cc += find_center(i);
		}
	}

	nth_element(cc.begin(), cc.begin()+1, cc.end());
	for (int i=1; i<(int)cc.size(); i++) {
		int u = cc[0].second;
		int v = cc[i].second;
		sol += {u, v};
		e[u] += v;
		e[v] += u;
	}

	{
		int diam;
		int x = naj(1);
		x = naj(x);
		diam = d[x];
		cout << diam << '\n';
	}

	for (auto p : sol)
		cout << p.first << ' ' << p.second << '\n';

}