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

	ll n, p;
	cin >> n >> p;
	for (ll i=0; i<=123123123; i++) {
		ll x = n - p*i;
		if (x < 0 && p > 0)
			break;
		ll pc = __builtin_popcountll(x);
		if (pc <= i && i <= x) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}