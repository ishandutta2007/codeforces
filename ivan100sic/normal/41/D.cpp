// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k;
int d[105][105][11];
char p[105][105][11];
int a[105][105];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;
	k++;

	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<m; j++) {
			a[i][j+1] = s[j] - '0';
		}
	}

	memset(d, 255, sizeof d);

	for (int j=1; j<=m; j++) {
		d[1][j][a[1][j] % k] = a[1][j];
	}

	for (int i=2; i<=n; i++) {
		for (int j=1; j<=m; j++) {

			auto go = [&](int u, char v) {
				for (int r=0; r<k; r++) {
					if (d[i-1][u][r] == -1) continue;
					int w = d[i-1][u][r] + a[i][j];
					if (w > d[i][j][w % k]) {
						d[i][j][w % k] = w;
						p[i][j][w % k] = v;
					}
				}
			};

			if (j > 1) go(j-1, 'L');
			if (j < m) go(j+1, 'R');
		}
	}

	int jj = 1, rr = 0;
	for (int j=1; j<=m; j++) {
		if (d[n][j][0] > d[n][jj][0]) {
			jj = j;
		}
	}

	if (d[n][jj][0] == -1) {
		cout << "-1\n";
		return 0;
	}

	cout << d[n][jj][0] << '\n';
	cout << jj << '\n';
	for (int i=n; i>1; i--) {
		char c = p[i][jj][rr];
		cout << c;
		int jj2 = (c == 'L' ? -1 : 1) + jj;
		rr = ((rr - a[i][jj]) % k + k) % k;
		jj = jj2;
	}
	cout << '\n';
}