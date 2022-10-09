#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 998244353;

void ad(int& x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int n, k;
int dp[1005], z[1005], sol;
int a[1005];
int nx[1005], q[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	k--;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	for (int w=1; k*w<=100000; w++) {
		for (int i=0; i<n; i++)
			while (nx[i] < n && a[nx[i]] - a[i] < w)
				nx[i]++;
		fill(dp, dp+n, 1);
		for (int i=0; i<k; i++) {
			memset(z, 0, sizeof(z));
			for (int j=0; j<n; j++) {
				ad(z[nx[j]], dp[j]);
			}
			int zz = 0;
			for (int j=0; j<n; j++) {
				ad(zz, z[j]);
				dp[j] = zz;
			}
		}
		for (int i=0; i<n; i++)
			ad(q[w], dp[i]);
	}
	int sol = 0;
	for (int w=1; w<=100000; w++)
		sol = (sol + w * 1ll * (MOD + q[w] - q[w+1])) % MOD;
	cout << sol << '\n';
}