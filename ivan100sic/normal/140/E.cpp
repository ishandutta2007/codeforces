#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, p;
int a[1000005];

int ad(int x, int y) {
	x += y;
	if (x >= p)
		x -= p;
	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0)
		x += p;
	return x;
}

int mul(int x, int y) {
	return x*1ll*y % p;
}

int ways[5005][5005];
int dalt[5005][5005];
int f[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> p;
	for (int i=0; i<n; i++)
		cin >> a[i];

	ways[0][0] = dalt[0][0] = f[0] = 1;
	for (int i=0; i<=5000; i++) {
		f[i+1] = mul(f[i], i+1);
		for (int j=0; j<=5000; j++) {
			if (j > 1) {
				ways[i+1][j] = ad(ways[i+1][j], mul(ways[i][j], j-1));
			}
			ways[i+1][j+1] = ad(ways[i+1][j+1], mul(ways[i][j], m-j));
			//
			if (j > 1) {
				dalt[i+1][j] = ad(dalt[i+1][j], mul(dalt[i][j], j-1));
			}
			dalt[i+1][j+1] = ad(dalt[i+1][j+1], dalt[i][j]);
		}
	}

	vector<int> dp(1, 1);

	for (int i=0; i<n; i++) {
		vector<int> nu(a[i]+1, 0);
		int z = accumulate(dp.begin(), dp.end(), 0, ad);
		for (int j=1; j<=a[i]; j++) {
			int q = mul(z, ways[a[i]][j]);
			if (j < (int)dp.size()) {
				q = sub(q, mul(f[j], mul(dp[j], dalt[a[i]][j])));
			}
			nu[j] = q;
			// cerr << i << ' ' << j << ": " << nu[j] << '\n';
		}
		swap(nu, dp);
	}

	cout << accumulate(dp.begin(), dp.end(), 0, ad) << '\n';
}