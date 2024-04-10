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

	ll n, q;
	cin >> n >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		ll br = (n*(x-1) + y + 1) / 2 + ((x+y)%2 ? (n*n+1)/2 : 0);
		cout << br << '\n';
	}
}