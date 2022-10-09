#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, p;
int dp[105][55];

int modd(int x) {
	if (x < 0)
		return x+p;
	else if (x >= p)
		return x-p;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> p;
	memset(dp, 128, sizeof dp);
	dp[0][0] = 0;
	int z = 0;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		z = (z+x) % p;
		vector<int> vz(55, -2e9);
		for (int l=0; l<k; l++) {
			for (int j=0; j<p; j++) {
				vz[l+1] = max(vz[l+1], dp[j][l] + modd(z-j+p));
			}
		}
		for (int i=0; i<55; i++)
			dp[z][i] = max(dp[z][i], vz[i]);
	}
	cout << dp[z][k] << '\n';
}