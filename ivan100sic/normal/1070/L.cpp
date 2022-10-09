#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[2005][2005], b[2005];
int n, m;

bool kec(basic_string<int> v) {
	for (int i : v) {
		int z = 0;
		for (int j : v)
			z += a[i][j];
		if (z & 1)
			return false;
	}
	return true;
}

void solve(basic_string<int> v) {
	if (kec(v)) {
		for (int i : v)
			b[i] = 1;
		return;
	}
	// nadji neparnog
	int x = -1;
	for (int i : v) {
		int z = 0;
		for (int j : v)
			z += a[i][j];
		if (z & 1) {
			x = i;
			break;
		}
	}

	// kompl, resi
	basic_string<int> sus;
	for (int i : v)
		if (a[x][i])
			sus += i;

	for (int x : sus)
		for (int y : sus)
			if (x != y)
				a[x][y] ^= 1;

	v.erase(v.find(x), 1);
	solve(v);

	basic_string<int> kec, dva;

	for (int i : sus) {
		if (b[i] == 1)
			kec += i;
		else
			dva += i;
	}

	if (kec.size() % 2 == 0)
		b[x] = 1;
	else
		b[x] = 2;

	for (int x : sus)
		for (int y : sus)
			if (x != y)
				a[x][y] ^= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				a[i][j] = 0;
		for (int i=1; i<=m; i++) {
			int u, v;
			cin >> u >> v;
			a[u][v] = 1;
			a[v][u] = 1;
		}
		fill(b+1, b+n+1, 0);
		basic_string<int> v;
		for (int i=1; i<=n; i++)
			v += i;
		solve(v);
		cout << *max_element(b+1, b+n+1) << '\n';
		for (int i=1; i<=n; i++)
			cout << b[i] << ' ';
		cout << '\n';
	}
}