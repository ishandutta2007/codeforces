#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll myclz(ll x) {
	if (!x) return -1;
	return 63 - __builtin_clzll(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	while (a || b) {
		int x = myclz(a);
		int y = myclz(b);
		if (x != y) {
			cout << (1ll << max(x+1, y+1)) - 1 << '\n';
			return 0;
		}
		a -= 1ll << x;
		b -= 1ll << x;
	}
	cout << "0\n";
}