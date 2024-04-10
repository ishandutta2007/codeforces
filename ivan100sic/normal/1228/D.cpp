#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
set<int> e[100005];
int c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].insert(y);
		e[y].insert(x);
	}

	fill(c+1, c+n+1, 1);

	for (int y : e[1]) {
		int col = 2;
		for (int z : e[y]) {
			if (c[z] == 2 && col == 2)
				col = 3;
			else if (c[z] == 3 && col == 3)
				return cout << "-1\n", 0;
		}
		c[y] = col;
	}

	ll f[4] = {0, 0, 0, 0};
	for (int i=1; i<=n; i++)
		f[c[i]]++;

	ll t = f[1] * f[2] + f[2] * f[3] + f[3] * f[1];

	if (t != m || *min_element(f+1, f+4) == 0)
		return cout << "-1\n", 0;

	for (int i=1; i<=n; i++)
		for (int y : e[i])
			if (c[i] == c[y])
				return cout << "-1\n", 0;

	for (int i=1; i<=n; i++)
		cout << c[i] << " \n"[i == n];
}