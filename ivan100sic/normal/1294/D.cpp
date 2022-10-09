#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll q, x, c[400005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> q >> x;
	multiset<pair<ll, ll>> ms;
	for (int i=0; i<x; i++)
		ms.insert({i, i});
	while (q--) {
		ll y;
		cin >> y;
		y %= x;
		ms.erase({c[y] * x + y, y});
		c[y]++;
		ms.insert({c[y] * x + y, y});
		cout << ms.begin()->first << '\n';
	}
}