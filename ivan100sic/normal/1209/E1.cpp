#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[4][105], n, m;
int d[105][16];

void mx(int& x, int y) {
	x = max(x, y);
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
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				cin >> a[i][j];

		memset(d, 192, sizeof d);
		d[0][0] = 0;

		for (int col=0; col<m; col++) {
			for (int mask=0; mask<(1<<n); mask++) {
				int cmpl = (1<<n) - 1 - mask;
				for (int sm=cmpl; sm; sm = (sm-1) & cmpl) {
					for (int j=0; j<n; j++) {
						int t = 0;
						for (int k=0; k<n; k++)
							if (sm & (1 << (j+k) % n))
								t += a[k][col];
						mx(d[col+1][mask | sm], d[col][mask] + t);
					}
				}
				mx(d[col+1][mask], d[col][mask]);
			}
		}

		cout << d[m][(1<<n)-1] << '\n';
	}
}