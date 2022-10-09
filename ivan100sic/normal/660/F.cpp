// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll a[200005], z[200005], w[200005];

template<class T, bool maximize = false>
struct lichao {
	struct line {
		T k, b;
		T operator() (T x) const { return k*x + b; }
	};

	int l;
	vector<line> a;
	// always pass +inf regardless of @maximize
	lichao(int l, int r, T inf) : l(l) {
		int maxn = 1;
		while (maxn < r-l)
			maxn <<= 1;
		a.assign(2*maxn, line{0, inf});
	}

	void add(line p, int x, int xl, int xr) {
		if (a[x](l+xl) <= p(l+xl) && a[x](l+xr) <= p(l+xr))
			return;
		if (p(l+xl) <= a[x](l+xl) && p(l+xr) <= a[x](l+xr)) {
			a[x] = p;
			return;
		}
		if (p(l+xl) < a[x](l+xl))
			swap(p, a[x]);
		int xm = (xl+xr) >> 1;
		add(p, 2*x  , xl  , xm);
		add(p, 2*x+1, xm+1, xr);
	}

	lichao& operator+= (line p) {
		if (maximize)
			p.k = -p.k, p.b = -p.b;
		add(p, 1, 0, (a.size()>>1)-1);
		return *this;
	}

	T operator() (int t) const {
		int x = t + (a.size() >> 1) - l;
		T v = a[0].b;
		for (; x; x >>= 1)
			v = min(v, a[x](t));
		return maximize ? -v : v;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		z[i+1] = z[i] + a[i];
		w[i+1] = w[i] + a[i]*1ll*i;
	}

	lichao<ll, true> drvo(-n, 1, 8e18);

	ll sol = 0;
	for (int l=n-1; l>=0; l--) {
		drvo += {z[l+1], w[l+1] + z[l+1]};
		sol = max(sol, drvo(-l) + l*z[l] - w[l] - z[l]);
	}
	cout << sol << '\n';
}