// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	ll n, z=0;
	cin >> n;
	map<ll, ll> h;
	for (ll i=0, x; i<n; i++) {
		cin >> x;
		z = max(z, h[x-i] += x);
	}
	cout << z << '\n';
}

// I will still practice daily...