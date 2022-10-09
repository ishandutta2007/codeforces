#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, k;
	cin >> n >> k;
	for (ll d=1; d<=n; d++) {
		if (n % d)
			continue;
		ll m = n / d;
		if (m >= k)
			continue;
		ll x = d*k + m;
		cout << x << '\n';
		return 0;		
	}
}