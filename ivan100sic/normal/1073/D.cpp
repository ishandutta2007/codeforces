#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		ll x;
		ll y;
		ll z;

		/* CONSTRUCTOR */
		node_t(ll x = 1123123123, ll y = 0, ll z = 0) : x(x), y(y), z(z) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = min(x, other.x);
			y += other.y;
			z += other.z;
			if (z >= 4e18)
				z = 4e18;
			if (y >= 4e18)
				y = 4e18;

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	node_t get(int l, int r, int node=1, int nl=0, int nr=MAXN-1) {
		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void set(int pos, node_t val) {
		pos += MAXN;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

typedef segtree<262144>::node_t node;

segtree<262144> drvo;
int n, pos, izbaci;
ll a[200005], t, sum, sol;
pair<ll, int> b[200005];

node node_pw(node a, ll pw) {
	if (pw == 0)
		return node();
	if (a.y * 1.0 * pw > 4e18)
		a.y = 4e18;
	else
		a.y = a.y * pw;

	if (a.z * 1.0 * pw > 4e18)
		a.z = 4e18;
	else
		a.z = a.z * pw;

	return a;
}

node cyclic_get(ll l, ll r) {
	node rez;
	if (r < l)
		return rez;

	if (r - l + 1 >= n) {
		rez = node_pw(drvo.get(0, n-1), (r-l+1) / n);
	}

	l %= n;
	r %= n;
	if (l <= r)
		return rez + drvo.get(l, r);
	else
		return drvo.get(l, n-1) + drvo.get(0, r) + rez;
}

void stepuj_segmentno() {
	ll ok = 0;
	ll skupo = b[izbaci].first;

	ll stop = 0;
	for (ll x=1; x<=(1ll<<60); x<<=1) {
		node g = cyclic_get(pos, pos + ok + x - 1);
		stop = 2*x;
		if (t - g.z >= skupo) {
			ok += x;
		} else {
			break;
		}
	}

	for (ll x=stop; x; x>>=1) {
		node g = cyclic_get(pos, pos + ok + x - 1);
		if (t - g.z >= skupo) {
			ok += x;
		}
	}
	node g = cyclic_get(pos, pos + ok - 1);
	sol += g.y;
	t -= g.z;
	pos = (pos + ok) % n;
}

void stepuj_obicno() {
	if (t >= a[pos]) {
		t -= a[pos];
		sol += 1;
	}

	pos += 1;
	if (pos == n)
		pos = 0;

	if (t < b[izbaci].first) {
		drvo.set(b[izbaci].second, node());
		izbaci++;
	}
}

/* ovo nema sanse da radi */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		sum += a[i];
		b[i] = {a[i], i};
	}
	sort(b, b+n);
	reverse(b, b+n);
	for (int i=0; i<n; i++)
		drvo.set(i, {a[i], 1, a[i]});

	while (izbaci < n) {
		stepuj_segmentno();
		stepuj_obicno();
		// cerr << t << ' ' << pos << ' ' << sol << '\n';
		if (t < b[n-1].first)
			break;
	}

	cout << sol << '\n';

}