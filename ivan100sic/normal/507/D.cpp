#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, m;
int d[1005][105];
int pw10[1005];

void ad(int& x, int y) {
	x += y;
	x -= (x >= m) * m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int j=n==1; j<10; j++)
		ad(d[1][j == 0 ? k : j%k], 1);

	pw10[0] = 1;
	for (int i=1; i<1005; i++)
		pw10[i] = pw10[i-1] * 10 % k;

	for (int i=2; i<=n; i++) {
		for (int r=0; r<=k; r++) {
			for (int j=i==n; j<10; j++) {
				int r2 = (j * pw10[i-1] + r) % k;
				if (r == 0) {
					r2 = 0;
				} else if (r2 == 0 && j == 0) {
					r2 = k;
				}

				ad(d[i][r2], d[i-1][r]);
			}
		}
	}
	cout << d[n][0] << '\n';
}