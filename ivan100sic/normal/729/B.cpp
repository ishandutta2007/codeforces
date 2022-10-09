#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[1005][1005];
int b[1005][1005];
int c[1005][1005];
int d[1005][1005];
int e[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
			b[i][j] = b[i-1][j] + a[i][j];
			c[i][j] = c[i][j-1] + a[i][j];
		}
	}

	int sol = 0;

	for (int i=n; i>=1; i--) {
		for (int j=m; j>=1; j--) {
			d[i][j] = d[i+1][j] + a[i][j];
			e[i][j] = e[i][j+1] + a[i][j];

			if (!a[i][j]) {
				if (b[i][j]) sol++;
				if (c[i][j]) sol++;
				if (d[i][j]) sol++;
				if (e[i][j]) sol++;
			}
		}
	}

	cout << sol << '\n';

}