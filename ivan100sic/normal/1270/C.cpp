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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		ll s = 0, z = 0;
		for (ll& x : a) {
			cin >> x;
			s += x;
			z ^= x;
		}
		ll u1 = z;
		s += z;
		z = 0;
		ll u2 = s;
		cout << "2\n" << u1 << ' ' << u2 << '\n';
	}	
}