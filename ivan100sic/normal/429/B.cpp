#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[1005][1005], b[1005][1005], c[1005][1005];
int d[1005][1005], e[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j] + max(b[i-1][j], b[i][j-1]);
			/*
			1.
			.2
			*/
		}
	}
	for (int i=n; i>=1; i--) {
		for (int j=m; j>=1; j--) {
			c[i][j] = a[i][j] + max(c[i+1][j], c[i][j+1]);
			/*
			2.
			.1
			*/
		}
	}

	for (int i=n; i>=1; i--) {
		for (int j=1; j<=m; j++) {
			d[i][j] = a[i][j] + max(d[i+1][j], d[i][j-1]);
			/*
			.2
			1.
			*/
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=m; j>=1; j--) {
			e[i][j] = a[i][j] + max(e[i-1][j], e[i][j+1]);
			/*
			.1
			2.
			*/
		}
	}

	int sol = 0;

	for (int i=2; i<n; i++) {
		for (int j=2; j<m; j++) {
			int v = 0;
			v = max(v, b[i-1][j] + c[i+1][j] + d[i][j-1] + e[i][j+1]);
			v = max(v, b[i][j-1] + c[i][j+1] + d[i+1][j] + e[i-1][j]);
			sol = max(sol, v);
		}
	}
	cout << sol << '\n';
}