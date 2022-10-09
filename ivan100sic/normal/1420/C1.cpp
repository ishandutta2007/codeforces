// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const ll inf = 1e18;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		ll dp[2] = {-inf, -inf};
		dp[0] = 0;
		for (int i=0; i<n; i++) {
			ll nu[2] = {-inf, -inf};
			nu[0] = max(dp[0], dp[1] - a[i]);
			nu[1] = max(dp[1], dp[0] + a[i]);
			copy(nu, nu+2, dp);
		}

		cout << max(dp[0], dp[1]) << '\n';
	}
}