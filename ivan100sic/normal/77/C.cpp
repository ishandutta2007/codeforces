// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[100005];
int a[100005];

ll d[100005];
int r[100005];

void dfs(int x, int p) {
	vector<pair<ll, int>> vr;
	for (int y : e[x]) {
		if (y == p) {
			continue;
		}

		dfs(y, x);
		vr.emplace_back(d[y], y);
	}

	sort(begin(vr), end(vr), greater<pair<ll, int>>());

	int t = min((int)vr.size(), a[x]-1);

	d[x] = 1;
	int rx = a[x] - t - 1;
	// cerr << x << ' ' << a[x] << ' ' << t << ' ' << rx << '\n';
	for (int i=0; i<t; i++) {
		int y = vr[i].second;
		d[x] += d[y] + 1;
		int dd = min(rx, r[y]);
		// cerr << "dd = " << dd << ' ' << rx << ' ' << r[y] << '\n';
		d[x] += 2 * dd;
		rx -= dd;
	}

	r[x] = rx;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	int s;
	cin >> s;
	a[s]++;

	dfs(s, s);

	// for (int i=1; i<=n; i++) {
	// 	cerr << i << ": " << d[i] << ' ' << r[i] << '\n';
	// }

	cout << d[s] - 1 << "\n";
}