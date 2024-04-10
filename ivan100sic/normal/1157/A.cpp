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

	ll x;
	cin >> x;
	set<ll> s;
	while (!s.count(x)) {
		s.insert(x);
		x++;
		while (x % 10 == 0)
			x /= 10;
	}
	cout << s.size() << "\n";
}