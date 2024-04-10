#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
	ordered_set;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct qry {
	int t, x, y;
};

int uncompressed[200005];

struct compressor {
	vector<int*> v;

	void add(int& x) {
		v.push_back(&x);
	}

	int run() {
		sort(v.begin(), v.end(), [](int* x, int* y) { return *x < *y; });
		int k = 0, last = -1;
		for (int i=0; i<(int)v.size(); i++) {
			if (i == 0 || *v[i] != last) {
				k++;
			}
			last = *v[i];
			uncompressed[k] = *v[i];
			*v[i] = k;
		}
		return k;
	}
};

struct rsq {
	int bs[400];
	int a[200005];

	void add(int x, int y);

	int sum(int x) {
		int z = 0;
		for (int i=0; i<(x>>9); i++)
			z += bs[i];
		for (int i=(x>>9)<<9; i<x; i++) {
			z += a[i];
		}
		return z + a[x];
	}
};

/*
	h[x] -> skup svih pozicija u nizu a gde se javlja vrednost x
	v[k] -> skup svih k-tih elemenata nizova h[...], uredjen da podrzava psq
	big  -> skup svih x takvih da h[x] ima strogo vise od MH elemenata
*/

const int MH = 500;

int n, q;
int a[100005];
ordered_set h[200005];
rsq v[MH+3];
set<int> big;
qry b[100005];

inline void rsq::add(int x, int y) {
	// cerr << "add " << this-v << ' ' << x << ' ' << y << '\n';
	bs[x>>9] += y;
	a[x] += y;
}

void update(int i, int x) {
	if (a[i] == x)
		return;
	// obrisi staru vrednost
	int j = h[a[i]].order_of_key(i) + 1;
	auto it = h[a[i]].find(i);
	++it;
	h[a[i]].erase(prev(it));
	if (j <= MH)
		v[j].add(i, -1);
	for (int p=j; it != h[a[i]].end() && p<=MH; p++) {
		// bio sam na p+1, sad sam na p
		v[p+1].add(*it, -1); // p+1 > MH, ok, idc
		v[p].add(*it, 1);
		++it;
	}
	if (h[a[i]].size() == MH)
		big.erase(a[i]);

	// dodaj novu vrednost
	j = h[x].order_of_key(i) + 1;
	it = h[x].lower_bound(i);
	for (int p=j; it != h[x].end() && p<=MH; p++) {
		// bio sam na p, sad sam na p+1
		v[p].add(*it, -1);
		v[p+1].add(*it, 1); // p+1 > MH, ok, idc
		++it;
	}
	h[x].insert(i);
	if (j <= MH)
		v[j].add(i, 1);
	if (h[x].size() == MH+1)
		big.insert(x);
	a[i] = x;
}

int solve(int r, int i) {
	if (r == 1)
		return uncompressed[a[i]];
	int k = 1 + h[a[i]].order_of_key(i);
	if (r % 2 == 0)
		return k;

	if (k <= MH)
		return v[k].sum(i);

	int z = 0;
	for (int b : big) {
		if ((int)h[b].size() < k)
			continue;
		z += *h[b].find_by_order(k-1) <= i;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	compressor cm;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		cm.add(a[i]);
	}

	cin >> q;

	for (int i=0; i<q; i++) {
		cin >> b[i].t >> b[i].x >> b[i].y;
		if (b[i].t == 1)
			cm.add(b[i].x);
	}

	int k = cm.run();

	for (int i=1; i<=n; i++)
		h[a[i]].insert(i);

	for (int i=1; i<=k; i++) {
		auto it = h[i].begin();
		int j = 1;
		while (j <= MH && it != h[i].end()) {
			v[j].add(*it, 1);
			j++;
			++it;
		}
		if (h[i].size() > MH)
			big.insert(i);
	}

	for (int i=0; i<q; i++) {
		if (b[i].t == 1)
			update(b[i].y, b[i].x);
		else
			cout << solve(b[i].x, b[i].y) << '\n';
	}
}