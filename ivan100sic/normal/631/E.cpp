#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct line {
	ll k, b;

	line() : k(0), b(-1e18) {}

	line(ll k, ll b) : k(k), b(b) {}

	ll operator* (ll x) const {
		return k*x + b;
	}
};

const int SIZE = 1 << 21;

struct lichao {
	line a[2*SIZE];

	void clear() {
		for (int i=0; i<2*SIZE; i++)
			a[i] = line();
	}

	void add(line p, int x=1, int lx=-1000000, int rx=1000000) {
		// prava a je svakako bolja od prave p svuda
		if (a[x]*lx >= p*lx && a[x]*rx >= p*rx)
			return;

		// prava p je bolja od a svuda
		if (p*lx >= a[x]*lx && p*rx >= a[x]*rx) {
			a[x] = p;
			return;
		}

		int mx = (lx + rx) >> 1;

		if (p*lx > a[x]*lx)
			swap(p, a[x]);

		add(p, 2*x, lx, mx);
		add(p, 2*x+1, mx+1, rx);
	}

	ll get(int p, int x=1, int lx=-1000000, int rx=1000000) const {
		if (p < lx || p > rx)
			return -1e18;
		ll ans = a[x]*p;
		if (x >= SIZE)
			return ans;

		int mx = (lx + rx) >> 1;
		return max({ans, get(p, 2*x, lx, mx), get(p, 2*x+1, mx+1, rx)});
	}

	ll operator* (int x) const {
		return get(x);
	}
};


int n;
ll a[200005], z[200005], sol;

lichao e;

void resi() {
	z[0] = 0;
	e.clear();
	for (int i=0; i<n; i++)
		z[i+1] = z[i] + a[i];
	for (int i=0; i<n; i++) {
		e.add(line(i, -z[i]));
		sol = max(sol, e*a[i] + z[i] - i*a[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	ll extra = 0;
	for (int i=0; i<n; i++)
		extra += (i+1)*a[i];

	resi();
	reverse(a, a+n);
	for (int i=0; i<n; i++)
		a[i] *= -1;
	resi();
	
	cout << sol + extra << '\n';
}