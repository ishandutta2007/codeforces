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

	ll r;
	cin >> r;
	for (ll x=1; x*x<=r; x++) {
		ll y = (r-x*x-x-1)/(2*x);
		if (y > 0 && x*x+2*x*y+x+1 == r) {
			cout << x << ' ' << y << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}