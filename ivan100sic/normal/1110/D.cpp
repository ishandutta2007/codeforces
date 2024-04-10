#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int c[1000009];
int d[1000009][5][3];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		c[x + 2]++;
	}

	memset(d, 128, sizeof(d));
	int sol = d[1][0][0] = 0;

	for (int q=2; q<=m+6; q++) {
		for (int i=0; i<5; i++) {
			for (int j=0; j<3; j++) {
				for (int k=0; k<3; k++) {
					if (i+k > c[q-2] || j+k > c[q-1] || k > c[q])
						continue;
					mx(d[q][j+k][k], d[q-1][i][j] + k + (c[q-2]-i-k) / 3);
				}
			}
		}
	}

	for (int i=0; i<5; i++)
		for (int j=0; j<3; j++)
			mx(sol, d[m+6][i][j]);

	cout << sol << '\n';
}