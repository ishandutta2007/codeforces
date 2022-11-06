#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

const int N = 18;

ll aTree[1 << N + 1], bTree[1 << N + 1];

void update(ll tree[], int p) {
	if (p < (1 << N)) tree[p] = tree[2 * p] + tree[2 * p + 1];
	if (p > 1) update(tree, p / 2);
}

ll sum(ll tree[], int l, int r) {
	if (l > r) return 0;
	if (l == r) return tree[l];
	ll ans = sum(tree, (l + 1) / 2, (r - 1) / 2);
	if (l % 2 == 1) ans += tree[l];
	if (r % 2 == 0) ans += tree[r];
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	forn(i, 0, (1 << (N + 1)) - 1) {
		aTree[i] = 0;
		bTree[i] = 0;
	}
	ll n, k, a, b, q;
	cin >> n >> k >> a >> b >> q;
	while(q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int d, v;
			cin >> d >> v;
			--d;
			ll old = aTree[d + (1 << N)];
			aTree[d + (1 << N)] = min(old + v, a);
			update(aTree, d + (1 << N));
			old = bTree[d + (1 << N)];
			bTree[d + (1 << N)] = min(old + v, b);
			update(bTree, d + (1 << N));
		} else {
			int p;
			cin >> p;
			--p;
			cout << sum(bTree, 1 << N, (1 << N) + p - 1) +
			sum(aTree, (1 << N) + p + k, (1 << (N + 1)) - 1) << '\n';

		}
	}
	return 0;
}