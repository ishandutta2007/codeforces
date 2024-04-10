#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct rac {
	ll x, y;

	rac(ll a, ll b) {
		x = a, y = b;
		if (y < 0)
			x *= -1, y *= -1;
	}

	bool operator< (const rac& b) const {
		return x*b.y < b.x*y;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<rac, ll> z;
	int n;
	cin >> n;
	while (n--) {
		ll k, x;
		cin >> k >> x;
		if (k) {
			z[rac(x, k)] += abs(k);
		}
	}
	int s=0;
	for (auto [a, b] : z)
		s += !!b;
	cout << s << '\n';
}