// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct segtree {
	int maxn;
	vector<T> a;
	T e;
	F f;

	segtree(int n, T e = T(), F f = F(), T v = T()) : e(e), f(f) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, v);
		for (int i=maxn-1; i; i--)
			a[i] = f(a[2*i], a[2*i+1]);
	}

	void add(int p, const T& v) {
		p += maxn;
		a[p] = f(a[p], v);
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	void update(int p, const T& v) {
		p += maxn;
		a[p] = v;
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	T get(int l, int r, int x, int xl, int xr) const {
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	T operator() (int l, int r) const {
		return get(l, r, 1, 0, maxn);
	}
};

struct seg {
	int l, r, i;
	bool operator< (const seg& b) const {
		return tuple(r, -l, i) < tuple(b.r, -b.l, b.i);
	}
} a[200005], b[200005];
int n;
basic_string<int> e[200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].i = i;
		e[a[i].l] += i;
	}

	set<seg> s;

	for (int i=1; i<=n; i++) {
		for (int j : e[i]) {
			s.insert(a[j]);
		}
		b[i-1] = *s.begin();
		s.erase(s.begin());
	}

	copy(b, b+n, a);
	vector<int> o1(n), o2;
	for (int j=0; j<n; j++) {
		o1[a[j].i] = j+1;
	}

	typedef pair<int, int> pii;
	segtree st(n+5, pii(-1, -1), [](pii x, pii y) { return max(x, y); });

	for (int j=1; j<=n; j++) {
		auto c = a[j-1];
		auto q = st(c.l, j);
		if (q.first >= j) {
			o2 = o1;
			swap(o2[c.i], o2[q.second]);
			break;
		}
		st.update(j, pii(c.r, c.i));
	}

	if (o2.size()) {
		cout << "NO\n";
		for (int x : o1)
			cout << x << ' ';
		cout << '\n';
		for (int x : o2)
			cout << x << ' ';
		cout << '\n';
	} else {
		cout << "YES\n";
		for (int x : o1)
			cout << x << ' ';
		cout << '\n';
	}

}