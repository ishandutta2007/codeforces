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

	ll n, sol=0;
	cin >> n;
	for (ll w=1; w<=10; w++) {
		ll lo = 1;
		for (ll i=0; i<w-1; i++)
			lo *= 10;
		ll hi = 10*lo - 1;
		sol += w * max(0ll, min(hi, n) - lo + 1);
	}
	cout << sol << '\n';
}