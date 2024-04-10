#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 1'000'000'007;

void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int a, b, k, t;
int dp[2][454545];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> k >> t;

	dp[0][222222] = 1;
	for (int i=0; i<2*t; i++) {
		auto ol = dp[i&1];
		auto nu = dp[(i&1)^1];
		memset(nu, 0, sizeof(dp[0]));
		for (int j=0; j<454545; j++) {
			if (ol[j]) {
				ad(nu[j-k], ol[j]);
				ad(nu[j+k+1], mod-ol[j]);
			}
		}
		for (int j=1; j<454545; j++)
			ad(nu[j], nu[j-1]);
	}

	int z = 0;
	for (int i=b-a+1+222222; i<454545; i++)
		ad(z, dp[0][i]);

	cout << z << '\n';
}