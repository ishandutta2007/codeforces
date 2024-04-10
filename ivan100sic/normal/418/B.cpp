#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct covek {
	int cost, mask, monitors;
	bool operator< (const covek& b) const {
		return monitors < b.monitors;
	}
};

int n, m, b;
covek a[105];
ll dp[1 << 20];

void mn(ll& x, ll y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> b;
	for (int i=0; i<n; i++) {
		int z;
		cin >> a[i].cost >> a[i].monitors >> z;
		while (z--) {
			int x;
			cin >> x;
			a[i].mask |= 1 << (x-1);
		}
	}

	sort(a, a+n);
	memset(dp, 63, sizeof(dp));
	dp[0] = 0;
	ll sol = 4e18;
	for (int i=0; i<n; i++) {
		for (int mask=(1<<m)-1; mask>=0; mask--) {
			mn(dp[mask | a[i].mask], dp[mask] + a[i].cost);
		}
		mn(sol, dp[(1<<m)-1] + 1ll*b*a[i].monitors);
	}
	if (sol > 3e18)
		sol = -1;
	cout << sol << '\n';
}