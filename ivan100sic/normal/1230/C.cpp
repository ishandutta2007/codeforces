#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool a[8][8];
int n, m;
int t[8];

int c[111], sol;

void prov() {
	memset(c, 0, sizeof c);
	int z = 0;
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (a[i][j])
				z += c[min(t[i], t[j])*10 + max(t[i], t[j])]++ == 0;
	sol = max(sol, z);
}

void rek(int d) {
	if (d == n+1) {
		prov();
		return;
	}

	for (int i=1; i<=6; i++) {
		t[d] = i;
		rek(d+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	rek(1);
	cout << sol << '\n';
}