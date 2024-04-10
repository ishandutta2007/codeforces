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

	for (ll x=1; x<=1000000; x++) {
		ll y = n-x;
		if (y < 0)
			continue;
		if (k == x*(x+1)/2 - y) {
			cout << y << '\n';
			return 0;
		}
	}
}