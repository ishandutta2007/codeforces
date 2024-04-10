#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005];
int b[100005];

bool probaj(ll x) {
	copy(a+1, a+n+1, b+1);
	int l = 0;
	for (int i=0; i<m; i++) {
		ll t = x;
		t -= l;
		while (t > 0 && l <= n) {
			ll w = min(t, (ll)b[l]);
			b[l] -= w;
			t -= w;
			if (b[l] == 0) {
				l++;
				t--; // nema veze ako je bilo 0
			}
		}
	}
	return accumulate(b+1, b+n+1, 0ll) == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	ll l = 0, r = 123123123123123123ll, o = -1;
	while (l <= r) {
		ll m = (l + r) >> 1;
		if (probaj(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << o << '\n';
}