#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[500005], n;
ll b[500005], c[500005];

struct fenw {
	vector<ll> a;

	fenw() : a(500005, 0) {}

	void add(ll x, ll y) {
		x++;
		while (x < 500005) {
			a[x] += y;
			x += x & -x;
		}
	}

	ll sum(ll x) {
		x++;
		ll y = 0;
		while (x) {
			y += a[x];
			x -= x & -x;
		}
		return y;
	}
} fw;

const int H = 524288;

struct stl {
	vector<ll> a, b;

	stl() : a(2*H, 0), b(2*H, 0) {}

	void push(int x) {
		if (!b[x])
			return;
		if (x < H) {
			b[2*x] += b[x];
			b[2*x+1] += b[x];
		}
		a[x] += b[x];
		b[x] = 0;
	}

	ll get() { return a[1]; }

	void update(int l, int r, ll val, int x = 1, int xl = 0, int xr = H-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] += val;
			push(x);
			return;
		}
		push(x);
		int xm = (xl + xr) >> 1;
		update(l, r, val, 2*x, xl, xm);
		update(l, r, val, 2*x+1, xm+1, xr);
		a[x] = max(a[2*x], a[2*x+1]);
	}
} gg;

void bump_up(int x) {
	gg.update(x, n, 1);
	gg.update(a[x]+1, x-1, -1);
	a[x]++;
}

void bump_dn(int x) {
	gg.update(x, n, -1);
	gg.update(a[x], x-1, 1);
	a[x]--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	sort(a+1, a+n+1, greater<ll>());
	ll par = accumulate(a+1, a+n+1, 0ll);
	n++;
	{
		ll curr = b[n] = 0;
		for (ll k=n-1; k>=1; k--) {
			curr -= fw.sum(n) - fw.sum(k);
			curr = b[k] = curr + min(a[k+1], (ll)k);
			fw.add(a[k+1], 1);
		}

		curr = 0;
		for (ll k=1; k<=n; k++) {
			curr += a[k];
			b[k] = curr - k*(k-1) - b[k];
		}
	}

	int nesto = 0;

	for (ll k=1; k<=n; k++)
		gg.update(k, k, b[k]);

	if (gg.get() <= 0 && (par + 0) % 2 == 0) {
		cout << "0 ";
		nesto = 1;
	}

	int pos = n;
	for (ll i=1; i<n; i++) {
		bump_up(pos);
		while (pos > 1 && a[pos] > a[pos-1]) {
			bump_up(pos-1);
			bump_dn(pos);
			pos--;
		}
		if (gg.get() <= 0 && (par + i) % 2 == 0) {
			cout << i << ' ';
			nesto = 1;
		}
	}
	if (!nesto)
		cout << "-1";
	cout << '\n';
}