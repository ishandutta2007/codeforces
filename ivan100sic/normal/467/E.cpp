#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x, y;

		/* CONSTRUCTOR */
		node_t(int x = 1123123123, int y = -1) : x(x), y(y) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			if (other.x < x)
				*this = other;
			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	void init() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t();
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void add(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] += val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}

	void set(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<524288> drvo;

int n;
int a[500005];
int u[500005], v;
int seen[1000005];
int first[1000005];
int cnt[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	copy(a, a+n, u);
	sort(u, u+n);
	v = unique(u, u+n) - u;
	for (int i=0; i<n; i++)
		a[i] = lower_bound(u, u+v, a[i]) - u;

	int l = 0;
	basic_string<int> sol;
	memset(seen, 0xff, sizeof seen);

	for (int i=0; i<n; i++) {
		int x = a[i];
		if (cnt[x] == 3 || (seen[x] != -1 && drvo.get(seen[x]+1, i-1).x
			< seen[x]))
		{
			if (cnt[x] == 3) {
				sol += {x, x, x, x};
			} else {
				int j = drvo.get(seen[x]+1, i-1).y;
				sol += {a[j], x, a[j], x};
			}
			for (int j=l; j<i; j++) {
				cnt[a[j]] = 0;
				seen[a[j]] = -1;
				first[a[j]] = -1;
				drvo.set(j, {});
			}
			l = i+1;
		} else {
			cnt[x]++;
			if (cnt[x] == 1) {
				first[x] = i;
			}
			seen[x] = i;
			drvo.set(i, {first[x], i});
		}
	}

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << u[x] << ' ';
	cout << '\n';
}