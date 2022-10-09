#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, sol;
int a[300005], c1, c2;
basic_string<int> e[300005];

complex<int> dfs(int x, int p) {
	complex<int> r = {a[x] == 1, a[x] == 2};
	for (int y : e[x]) {
		if (y == p)
			continue;
		r += dfs(y, x);
	}
	if (!((r.real() > 0 && r.imag() > 0) || (c1-r.real() > 0 && c2-r.imag() > 0)))
		sol++;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	c1 = count(a+1, a+n+1, 1);
	c2 = count(a+1, a+n+1, 2);

	dfs(1, 1);
	cout << sol << '\n';
}