#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAXN = 1048576;

struct lazyseg {
	vector<ll> a, b;

	lazyseg() : a(2*MAXN), b(2*MAXN) {}

	void push(int x, int xl, int xr) {
		if (!b[x]) return;
		if (x < MAXN) {
			b[2*x] += b[x];
			b[2*x+1] += b[x];
		}
		a[x] += b[x] * (xr-xl+1);
		b[x] = 0;
	}

	void update(int l, int r, ll v, int x=1, int xl=1, int xr=MAXN) {
		if (r < xl || xr < l) {
			push(x, xl, xr);
			return;
		}

		if (l <= xl && xr <= r) {
			b[x] += v;
			push(x, xl, xr);
			return;
		}

		push(x, xl, xr);

		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		a[x] = a[2*x] + a[2*x+1];
	}

	ll query(int l, int r, int x=1, int xl=1, int xr=MAXN) {
		push(x, xl, xr);
		if (r < xl || xr < l)
			return 0;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, xl, xm)
			+ query(l, r, 2*x+1, xm+1, xr);
	}
} drvo;

typedef int niz[1000005];

int n, q;
niz a, al, ar, ql, qr, l, r, p;

template<class T, class U>
void cartesian_tree(const T& a, U& l, U& r, U& p) {
	for (int i=1; i<=n; i++) {
		p[i] = i-1;
		r[i-1] = i;
		while (p[i] && a[i] > a[p[i]]) {
			int j = p[i];
			int k = p[j];
			int v = l[i];
			// rotiraj
			p[i] = k; r[k] = i;
			p[j] = i; l[i] = j;
			p[v] = j; r[j] = v;
		}
	}
}

void cartesian_dfs(int x) {
	al[x] = ar[x] = x;
	if (l[x]) {
		cartesian_dfs(l[x]);
		al[x] = al[l[x]];
	}
	if (r[x]) {
		cartesian_dfs(r[x]);
		ar[x] = ar[r[x]];
	}
}

struct stvar {
	int id, sgn, l, r;
};

basic_string<stvar> e[1000005];
ll ans[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=0; i<q; i++)
		cin >> ql[i];
	for (int i=0; i<q; i++)
		cin >> qr[i];

	for (int i=0; i<q; i++) {
		e[ql[i]-1] += stvar{i, -1, ql[i], qr[i]};
		e[qr[i]]   += stvar{i, +1, ql[i], qr[i]};
	}

	cartesian_tree(a, l, r, p);
	cartesian_dfs(r[0]);

	for (int i=1; i<=n; i++) {
		drvo.update(al[i], ar[i], 1);
		for (auto [i, s, l, r] : e[i]) {
			ans[i] += s * drvo.query(l, r);
		}
	}

	for (int i=0; i<q; i++)
		cout << ans[i] << " \n"[i == q-1];
}