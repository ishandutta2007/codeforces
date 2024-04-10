#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	ll z = 0;
	for (ll i=1; i<=n; i++) {
		ll y;
		cin >> y;
		z += y;
	}
	z += n-1;
	cout << (z == x ? "YES" : "NO");
}