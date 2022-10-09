#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, q;
ll A[100005], B[100005];

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		ll amount;

		updater(ll amount = 0) : amount(amount) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			amount += other.amount;

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return amount != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		ll sum_even, sum_odd, len_even, len_odd;

		/* CONSTRUCTOR */
		node_t() : sum_even(0), sum_odd(0), len_even(0), len_odd(0) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			sum_even += other.sum_even;
			sum_odd += other.sum_odd;
			len_odd += other.len_odd;
			len_even += other.len_even;
			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			sum_even += len_even * other.amount;
			sum_odd += len_odd * other.amount;
			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];
	updater b[2*MAXN];

	void init(ll* A, int n) {
		for (int i=1; i<=n; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			if (i % 2) {
				a[i + MAXN - 1].sum_odd = A[i];
				a[i + MAXN - 1].len_odd = 1;
			} else {
				a[i + MAXN - 1].sum_even = A[i];
				a[i + MAXN - 1].len_even = 1;
			}
		}

		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	void push(int i) {
		if (b[i]) {
			a[i] += b[i];
			if (i < MAXN) {
				b[2*i] += b[i];
				b[2*i+1] += b[i];
			}
			b[i] = updater();
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void update(int l, int r, updater val, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			a[node] += val;
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;
		update(l, r, val, 2*node, nl, nm);
		update(l, r, val, 2*node+1, nm+1, nr);
		a[node] = a[2*node] + a[2*node+1];
	}
};

segtree_lazy<131072> drvoA, drvoB;

ll c[100005];

ll aps(ll x) {
	return x < 0 ? -x : x;
}

ll closest(set<ll>& s, ll x) {
	auto it = s.lower_bound(x);

	if (it != s.end()) {
		ll sol = *it;
		if (it == s.begin()) {
			return sol;
		} else {
			if (abs(*prev(it) - x) < abs(sol - x)) {
				return *prev(it);
			} else {
				return sol;
			}
		}
	} else {
		return *prev(it);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<=n; i++) {
		cin >> A[i];
	}
	for (int i=1; i<=m; i++) {
		cin >> B[i];
	}

	drvoA.init(A, n);
	drvoB.init(B, m);

	auto adidas = drvoA.get(1, n);

	ll drvoVal = adidas.sum_odd - adidas.sum_even;

	for (int j=0; j<=m-n; j++) {

		auto bb = drvoB.get(1+j, n+j);
		if (j % 2) {
			swap(bb.sum_even, bb.sum_odd);
		}

		c[j] = bb.sum_even - bb.sum_odd + drvoVal;
		// cerr << "c: " << c[j] << '\n';
	}

	set<ll> cc(c, c+m-n+1);

	cout << abs(closest(cc, 0)) << '\n';

	for (int i=1; i<=q; i++) {
		int l, r;
		ll x;
		cin >> l >> r >> x;

		if (r - l > 2) {
			r -= (r - l) / 2 * 2;
		}
		drvoA.update(l, r, x);

		auto adidas = drvoA.get(1, n);

		//cerr << adidas.sum_odd << ' ' << adidas.sum_even << ' '
		//	 << adidas.len_odd << ' ' << adidas.len_even << '\n';

		ll drvoValNu = adidas.sum_odd - adidas.sum_even;	

		ll cumulative  = drvoVal - drvoValNu;

		// cerr << "target is: " << cumulative << '\n';

		cout << aps(closest(cc, cumulative) - cumulative) << '\n';
	}


}

/*

5 6 3
1 2 3 4 5
1 2 3 4 5 6
1 1 10
1 1 -9
1 5 -1

*/