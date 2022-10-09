#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct road {
	ll a, b, c;

	ll side(ll x, ll y) const {
		ll t = a*x + b*y + c;
		if (t < 0) return -1;
		if (t > 0) return 1;
		return 0;
	}
};

int n;
ll xc, yc, xt, yt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> xc >> yc >> xt >> yt >> n;
	int z = 0;
	for (int i=0; i<n; i++) {
		road r;
		cin >> r.a >> r.b >> r.c;
		if (r.side(xc, yc) != r.side(xt, yt))
			z++;
	}
	cout << z << '\n';
}