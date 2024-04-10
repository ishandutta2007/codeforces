// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T, class U, class F, class G, class H>
struct segtreelazy {
	struct node { T v; U u; };
	int maxn;
	vector<node> a;
	T e; U eu;
	F f; G g; H h;
	// Add two elements
	// Add two updaters
	// Add an element and an update
	// Neutral element
	// Neutral update
	// Bottom level element
	segtreelazy(int n, F f, G g, H h, T e = T(), U eu = U(), T v = T()) :
		e(e), eu(eu), f(f), g(g), h(h)
	{
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, node{v, eu});
		for (int i=maxn-1; i; i--)
			a[i].v = f(a[2*i].v, a[2*i+1].v);
	}

	void push(int x) {
		a[x].v = h(a[x].v, a[x].u);
		if (x < maxn) {
			a[2*x  ].u = g(a[2*x  ].u, a[x].u);
			a[2*x+1].u = g(a[2*x+1].u, a[x].u);
		}
		a[x].u = eu;
	}

	void update(int l, int r, const U& u, int x, int xl, int xr) {
		if (r <= xl || xr <= l)
			return push(x);
		if (l <= xl && xr <= r)
			return a[x].u = g(a[x].u, u), push(x);
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, u, 2*x  , xl, xm);
		update(l, r, u, 2*x+1, xm, xr);
		a[x].v = f(a[2*x].v, a[2*x+1].v);
	}

	T get(int l, int r, int x, int xl, int xr) {
		push(x);
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x].v;
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	void update(int l, int r, const U& u) { update(l, r, u, 1, 0, maxn); }
	T operator() (int l, int r) { return get(l, r, 1, 0, maxn); }
};

int n, k;
int a[200005];

int overlap(int x, int y) {
	for (int i=k; i>=1; i--) {
		if ((x & ((1 << i) - 1)) == (y >> (k - i))) {
			return i;
		}
	}
	return 0;
}

int bitrev(int x) {
	int y = 0;
	for (int i=0; i<k; i++) {
		y = (y << 1) | (x & 1);
		x >>= 1;
	}
	return y;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		k = s.size();
		int x = 0;
		for (int i=0; i<k; i++) {
			x = 2*x + (s[i] == '1');
		}
		a[i] = x;
	}

	segtreelazy drvo(
		1 << k,
		[](int x, int y) { return min(x, y); },
		plus<int>(),
		plus<int>(),
		int(1e9),
		0,
		int(5e8)
	);

	// nista = cena da ih sve ulancam
	int nista = k, zadnji = a[0];

	for (int i=1; i<n; i++) {
		int x = a[i];
		// kacim na zadnjeg, svima iz matrice se cost poveca za k-overlap
		int bump = k - overlap(zadnji, x);
		// kacim na nesto u matrici, ali na sta?
		int oldmatsol = nista + k;

		int sirina = 1 << k, xrev = bitrev(x);
		for (int ml=0; ml<=k; ml++) {
			int baza = (xrev << (k - ml)) & ((1 << k) - 1);
			oldmatsol = min(oldmatsol, drvo(baza, baza + sirina) + k - ml);
			sirina >>= 1;
			if (ml < k) {
				baza += sirina * (1 & (x >> (k - 1 - ml)));
			}
		}

		int ijndaz = bitrev(zadnji);

		drvo.update(0, 1 << k, bump);
		drvo.update(ijndaz, ijndaz+1, oldmatsol - drvo(ijndaz, ijndaz+1));
		nista += bump;

		zadnji = x;
	}

	cout << min(nista, drvo(0, 1 << k)) << '\n';
}