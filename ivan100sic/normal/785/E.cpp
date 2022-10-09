#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

template<int order>
struct pa {
	typedef pa<order-1> half_t;

	static const int H = 1 << (order-1);

	int sum;
	half_t* l;
	half_t* r;

	pa() : sum(0), l(nullptr), r(nullptr) {}

	int getsum() {
		return sum;
	}

	void insert(int x) {
		if (x < H) {
			if (!l) l = new half_t();
			l->insert(x);
		} else {
			if (!r) r = new half_t();
			r->insert(x - H);
		}
		sum = (l ? l->getsum() : 0) + (r ? r->getsum() : 0);
	}

	void erase(int x) {
		if (x < H) {
			if (!l) return;
			l->erase(x);
		} else {
			if (!r) return;
			r->erase(x - H);
		}
		sum = (l ? l->getsum() : 0) + (r ? r->getsum() : 0);
	}

	int count_less(int x) {
		if (x < H) {
			if (!l) {
				return 0;
			} else {
				return l->count_less(x);
			}
		} else {
			int y = 0;
			if (l) {
				y += l->getsum();
			}
			if (!r) {
				return y;
			} else {
				return y + r->count_less(x - H);
			}
		}
	}
};

template<>
struct pa<6> {

	unsigned long long mask;

	pa() : mask(0) {}

	void insert(int x) {
		mask |= 1ull << x;
	}

	void erase(int x) {
		mask &= ~(1ull << x);
	}

	int getsum() {
		return __builtin_popcountll(mask);
	}

	int count_less(int x) {
		unsigned long long xmask = (1ull << x) - 1;
		return __builtin_popcountll(mask & xmask);
	}
};

typedef pa<18> pera;

const int MAXN = 262144;

struct tree {
	pera aa[2*MAXN];

	void insert(int pos, int val) {
		pos += MAXN - 1;
		while (pos >= 1) {
			aa[pos].insert(val);
			pos >>= 1;
		}
	}

	void erase(int pos, int val) {
		pos += MAXN - 1;
		while (pos >= 1) {
			aa[pos].erase(val);
			pos >>= 1;
		}
	}

	int range_sum(int l, int r, int a, int b, int node=1, int nl=1, int nr=MAXN) {
		if (l > r) {
			return 0;
		}
		if (nr < l || r < nl) {
			return 0;
		}
		if (l <= nl && nr <= r) {
			return max(0, aa[node].count_less(b+1) - aa[node].count_less(a));
		}

		int nm = (nl + nr) >> 1;

		return range_sum(l, r, a, b, 2*node, nl, nm) +
			range_sum(l, r, a, b, 2*node+1, nm+1, nr);
	}
} drvo;

int n, q;
int a[200005];

long long sol;

void test() {
	pera a;

	for (int i=1; i<=100; i++) {
		a.insert(i);
	}

	for (int i=1; i<=50; i++) {
		a.erase(2*i);
	}

	cerr << a.count_less(101) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// test();

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		a[i] = i;
		drvo.insert(i, i);
	}

	for (int i=1; i<=q; i++) {
		int l, r;
		cin >> l >> r;

		if (l > r) {
			swap(l, r);
		}

		if (l != r) {
			int v1 = drvo.range_sum(l+1, r-1, a[r]+1, n);
			int v2 = drvo.range_sum(l+1, r-1, a[l]+1, n);

			int v3 = drvo.range_sum(l+1, r-1, 1, a[l]-1);
			int v4 = drvo.range_sum(l+1, r-1, 1, a[r]-1);

			sol += v2 - v1 + v4 - v3;

			drvo.erase(l, a[l]);
			drvo.erase(r, a[r]);

			swap(a[l], a[r]);

			drvo.insert(l, a[l]);
			drvo.insert(r, a[r]);

			if (a[l] > a[r]) {
				sol++;
			} else {
				sol--;
			}
		}

		cout << sol << '\n';
	}

}