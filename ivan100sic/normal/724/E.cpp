#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, c;
int a[10005], b[10005];
ll dp[2][10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];

	memset(dp, 63, sizeof(dp));
	dp[0][0] = 0;
	for (int i=1; i<=n; i++) {
		auto ol = dp[1-i%2];
		auto nu = dp[i%2];
		memset(nu, 63, sizeof(dp[0]));
		for (int j=0; j<=i; j++) {
			// obojicu brisem
			// nu[j] = min(nu[j], ol[j] + a[i] + b[i]);
			// brisem gore
			nu[j] = min(nu[j], ol[j] + a[i] + j*1ll*c);
			// brisem dole
			if (j) nu[j] = min(nu[j], ol[j-1] + b[i]);
		}
	}
	cout << *min_element(dp[n%2], dp[n%2]+n+1) << '\n';
}