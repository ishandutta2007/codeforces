#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;

int d[44][64][64], pc[64];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	if (n < m)
		swap(n, m);

	for (int i=0; i<64; i++)
		pc[i] = __builtin_popcount(i);

	int mm = (1<<m) - 1;
	memset(d, 63, sizeof(d));
	d[0][mm][0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<=mm; j++) {
			for (int k=0; k<=mm; k++) {
				int v = d[i][j][k];
				for (int l=0; l<=mm; l++) {
					int x = j | l;
					if (x != mm)
						continue;
					int y = (k | l | (l<<1) | (l>>1)) & mm;
					int z = l;
					mn(d[i+1][y][z], v + pc[l]);	
				}
			}
		}
	}

	int sol = 1e9;
	for (int i=0; i<=mm; i++)
		mn(sol, d[n][mm][i]);
	cout << n*m - sol << '\n';
}