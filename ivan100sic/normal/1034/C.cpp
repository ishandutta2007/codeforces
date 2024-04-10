#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll s[1000005];
int n;
int p[1000005];
ll c[1000005];

ll q[5005], m, dp[5005];
const int mod = 1'000'000'007;

void ad(ll& x, ll y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> s[i];
	for (int i=2; i<=n; i++)
		cin >> p[i];
	for (int i=n; i>1; i--)
		s[p[i]] += s[i];
	for (int i=2; i<=n; i++) {
		ll g = gcd(s[i], s[1]);
		ll k = s[1] / g;
		for (ll x=1; x*k<=n && x <= g; x++) {
			if (g % x == 0) {
				c[x*k]++;
			}
		}
	}

	for (int i=1; i<=n; i++)
		if (c[i] == i-1)
			q[m++] = s[1] / i;

	sort(q, q+m);

	ll z = 0;
	for (int i=0; i<m; i++) {
		dp[i] = 1;
		for (int j=0; j<i; j++)
			if (q[i] % q[j] == 0)
				ad(dp[i], dp[j]);
		ad(z, dp[i]);
	}

	cout << dp[m-1] << '\n';
}