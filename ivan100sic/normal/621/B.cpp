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

	map<ll, ll> a, b;
	int n;
	cin >> n;
	while (n--) {
		ll x, y;
		cin >> x >> y;
		a[x+y]++;
		b[x-y]++;
	}

	ll sol = 0;
	for (auto p : a)
		sol += p.second*(p.second-1);
	for (auto p : b)
		sol += p.second*(p.second-1);
	cout << sol/2 << '\n';
}