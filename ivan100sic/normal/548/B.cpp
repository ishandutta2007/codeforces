// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[505][505];
int r[505];
int n, m, q, sol;

void rc(int x) {
	int z = 0;
	r[x] = 0;
	for (int y=1; y<=m; y++) {
		z = a[x][y] ? z+1 : 0;
		r[x] = max(r[x], z);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++)
			cin >> a[i][j];
		rc(i);
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		a[x][y] ^= 1;
		rc(x);
		cout << *max_element(r+1, r+n+1) << '\n';
	}
}

// I will still practice daily...