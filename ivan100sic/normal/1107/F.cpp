#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stvar {
	ll a, b, k;

	bool operator< (stvar x) const {
		return b > x.b;
	}

} a[505];

ll dp[505][505];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i].a >> a[i].b >> a[i].k;

	sort(a+1, a+n+1);

	ll sol = 0;

	for (int i=1; i<=n; i++) {
		ll flat = a[i].a - a[i].b * a[i].k;
		for (int j=0; j<=n; j++) {
			ll line = a[i].a - a[i].b * (j - 1);
			dp[i][j] = max({
				j ? dp[i-1][j-1] + line : 0ll,
				0ll,
				dp[i-1][j],
				dp[i-1][j] + flat,
			});
			sol = max(sol, dp[i][j]);
		}
	}

	cout << sol << '\n';

}