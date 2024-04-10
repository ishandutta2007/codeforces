#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[505];

int z[505][505], w[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> s[i];
		s[i] = string(" ") + s[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<m; j++) {
			z[i][j] = z[i-1][j] + z[i][j-1] - z[i-1][j-1] +
				(s[i][j] == '.' && '.' == s[i][j+1]);
		}
	}
	for (int i=1; i<n; i++) {
		for (int j=1; j<=m; j++) {
			w[i][j] = w[i-1][j] + w[i][j-1] - w[i-1][j-1] +
				(s[i][j] == '.' && '.' == s[i+1][j]);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--;
		int sol = 0;
		
		sol += z[a][b];
		sol += z[c][d-1];
		sol -= z[a][d-1];
		sol -= z[c][b];

		sol += w[a][b];
		sol += w[c-1][d];
		sol -= w[a][d];
		sol -= w[c-1][b];

		cout << sol << '\n';
	}
}