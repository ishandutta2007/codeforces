// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, q;
ll a[1 << 19];
int flip[20];

void postavi(int p, int v, int x, int xl, int xr, int lv) {
	if (p < xl || p >= xr) return;
	if (xr - xl == 1) {
		a[x] = v;
		return;
	}

	int xm = (xl+xr) >> 1;
	postavi(p, v, 2*x^flip[lv]^0, xl, xm, lv-1);
	postavi(p, v, 2*x^flip[lv]^1, xm, xr, lv-1);
	a[x] = a[2*x] + a[2*x+1];
}

ll sumbiraj(int l, int r, int x, int xl, int xr, int lv) {
	if (r <= xl || xr <= l) return 0;
	if (l <= xl && xr <= r) return a[x];
	int xm = (xl+xr) >> 1;
	return
		sumbiraj(l, r, 2*x^flip[lv]^0, xl, xm, lv-1) +
		sumbiraj(l, r, 2*x^flip[lv]^1, xm, xr, lv-1);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> q;
	for (int i=0; i<(1<<n); i++) {
		ll x;
		cin >> x;
		for (int j=i+(1<<n); j; j>>=1) {
			a[j] += x;
		}
	}

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, k;
			cin >> x >> k;
			x--;
			postavi(x, k, 1, 0, 1<<n, n);
		} else if (t == 4) {
			int l, r;
			cin >> l >> r;
			l--;
			cout << sumbiraj(l, r, 1, 0, 1<<n, n) << '\n';
		} else if (t == 3) {
			int k;
			cin >> k;
			flip[k+1] ^= 1;
		} else {
			int k;
			cin >> k;
			for (int j=k; j>=1; j--) {
				flip[j] ^= 1;
			}
		}
	}

}