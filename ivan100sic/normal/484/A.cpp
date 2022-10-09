#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll same(ll x) {
	if (!x) return 0;
	while (x != (x&-x))
		x -= x&-x;
	return x;
}

ll solve(ll a, ll b) {
	if (a == b)
		return a;
	if (same(a) == same(b)) {
		ll k = same(a);
		return k + solve(a-k, b-k);
	}
	ll h = max(a, b);
	if ((h+1) == ((h+1)&(-h-1)))
		return h;
	else
		return max(same(a), same(b)) - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}
}