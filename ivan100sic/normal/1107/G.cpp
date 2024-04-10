#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAXN = 524288;

struct stl {
	vector<ll> a, b;
	
	stl() : a(2*MAXN, 0), b(2*MAXN, 0) {}

	void push(int x) {
		if (x < MAXN) {
			b[2*x] += b[x];
			b[2*x+1] += b[x];
		}
		a[x] += b[x];
		b[x] = 0;
	}

	void update(int l, int r, ll v, int x = 1, int xl = 0, int xr = MAXN-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] += v;
			push(x);
			return;
		}
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x  , xl  , xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		a[x] = max(a[2*x], a[2*x+1]);
	}

	ll get(int l, int r, int x = 1, int xl = 0, int xr = MAXN-1) {
		push(x);
		if (r < xl || xr < l) {
			return -123123123123123123ll;
		}
		if (l <= xl && xr <= r) {
			return a[x];
		}
		int xm = (xl+xr) >> 1;
		return max(
			get(l, r, 2*x  , xl  , xm),
			get(l, r, 2*x+1, xm+1, xr)
		);
	}
};

struct seg {
	int l, r;
	ll v;
};

ll n, a;
ll d[300005], c[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a;
	for (int i=1; i<=n; i++)
		cin >> d[i] >> c[i];

	stl drvo;
	basic_string<seg> stek;
	ll sol = 0;

	for (int i=1; i<=n; i++) {
		drvo.update(1, i, a - c[i]);
		if (i > 1) {
			ll g = (d[i] - d[i-1]) * (d[i] - d[i-1]);
			int lcut = i-1;
			while (stek.size() && stek.back().v <= g) {
				auto [l, r, v] = stek.back();
				stek.pop_back();
				lcut = l;
				drvo.update(l, r, v);
			}
			stek += {lcut, i-1, g};
			drvo.update(lcut, i-1, -g);
		}
		sol = max(sol, drvo.get(1, i));
	}
	cout << sol << '\n';
}