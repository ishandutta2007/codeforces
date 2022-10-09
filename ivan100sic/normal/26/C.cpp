#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, a, b, c, u;
int d[105][105];
int col[10005];

void no() {
	cout << "IMPOSSIBLE\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> a >> b >> c;
	int nn = n, mm = m;
	if (n % 2 && m % 2)
		no();

	if (n % 2) {
		// poplocaj zadnju vrstu sa c
		if (a < m/2)
			no();
		for (int i=1; i<=m; i+=2)
			(d[n][i] = d[n][i+1] = ++u), a--;
		n--;
	}

	if (m % 2) {
		// poplocaj zadnju vrstu sa c
		if (b < n/2)
			no();
		for (int i=1; i<=n; i+=2)
			(d[i][m] = d[i+1][m] = ++u), b--;
		m--;
	}

	for (int i=1; i<=n; i+=2) {
		for (int j=1; j<=m; j+=2) {
			if (c) {
				d[i][j] = d[i+1][j] = d[i][j+1] = d[i+1][j+1] = ++u;
				c--;
			} else if (a >= 2) {
				d[i][j] = d[i][j+1] = ++u;
				d[i+1][j] = d[i+1][j+1] = ++u;
				a -= 2;
			} else if (b >= 2) {
				d[i][j] = d[i+1][j] = ++u;
				d[i][j+1] = d[i+1][j+1] = ++u;
				b -= 2;
			} else {
				no();
			}
		}
	}

	for (int i=1; i<=nn; i++) {
		for (int j=1; j<=mm; j++) {
			if (!col[d[i][j]]) {
				col[d[i][j]] = 1+i%5+j%5*5;
			}
			cout << char('a'+col[d[i][j]]);
		}
		cout << '\n';
	}

}