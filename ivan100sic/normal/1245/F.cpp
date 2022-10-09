#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll l2(ll x) {
	return 31 - __builtin_clz(x);
}

ll p3[44];

ll solve2(ll l, ll r, ll al, ll ar, ll xl, ll xr) {
	if (r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r) {
		if (al & xl) return 0;

		ll w1 = l2(xr-xl+1), w2 = l2(ar-al+1);
		ll t = p3[min(w1, w2)];
		for (int i=min(w1, w2); i<max(w1, w2); i++)
			if (!((al ^ xl) & (1 << i)))
				t *= 2;
		return t;
	}

	ll xm = (xl+xr) >> 1;
	return solve2(l, r, al, ar, xl, xm)
		 + solve2(l, r, al, ar, xm+1, xr);
}

ll solve1(ll l, ll r, ll xl, ll xr) {
	if (r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r)
		return solve2(l, r, xl, xr, 0, (1<<30) - 1);

	ll xm = (xl+xr) >> 1;
	return solve1(l, r, xl, xm) + solve1(l, r, xm+1, xr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	p3[0] = 1;
	for (int i=1; i<44; i++)
		p3[i] = p3[i-1] * 3;

	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		ll z = solve1(l, r, 0, (1 << 30)-1);
		cout << z << '\n';
	}

	
}