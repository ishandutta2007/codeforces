#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct compressor {
	vector<int*> v;

	void add(int* x) {
		v.push_back(x);
	}

	int run() {
		sort(v.begin(), v.end(), [](int* x, int* y) { return *x < *y; });
		int k = 0, last = -1;
		for (int i=0; i<(int)v.size(); i++) {
			if (i == 0 || *v[i] != last) {
				k++;
			}
			last = *v[i];
			*v[i] = k;
		}
		return k;
	}
};

const ll BIG = 4012012012;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
	ordered_set;

struct person {
	int inc, pref;
};

struct dish {
	int p, s, b;
};

struct stvar {
	int id, x, y, z;
	bool operator< (const stvar& b) const {
		if (x != b.x)
			return x > b.x;
		return id < b.id;
	}
};

int n, m;
dish a[100005];
person b[100005];
stvar c[200005];
int ans[100005];

const int MAXN = 262144;
ordered_set d[2*MAXN]; int t;

void add0(int u, int v) {
	u += MAXN;
	while (u > 0) {
		d[u].insert(v * BIG + (++t));
		u >>= 1;
	}
}

int get0(int u, int v, int x=1, int xl=0, int xr=MAXN-1) {
	if (u < xl)
		return 0;
	if (xr <= u)
		return d[x].order_of_key(v * BIG + BIG - 444);
	int xm = (xl+xr) >> 1;
	return
		get0(u, v, 2*x, xl, xm) +
		get0(u, v, 2*x+1, xm+1, xr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i].p;
	for (int i=0; i<n; i++)
		cin >> a[i].s;
	for (int i=0; i<n; i++)
		cin >> a[i].b;
	for (int i=0; i<m; i++)
		cin >> b[i].inc;
	for (int i=0; i<m; i++)
		cin >> b[i].pref;

	for (int i=0; i<n; i++)
		c[i] = {0, a[i].s, a[i].b + a[i].p, a[i].p - a[i].b};
	for (int i=0; i<m; i++)
		c[i+n] = {i+1, b[i].inc, b[i].inc + b[i].pref, b[i].inc - b[i].pref};

	sort(c, c+n+m);

	{
		compressor komp;
		for (int i=0; i<n+m; i++) {
			komp.add(&c[i].y);
		}
		 komp.run();
	}

	for (int i=0; i<n+m; i++) {
//		cerr << "processing " << c[i].id << ' ' << c[i].x << ' ' << c[i].y << ' ' << c[i].z << '\n';
		if (c[i].id == 0) {
			add0(c[i].y, c[i].z);
		} else {
			ans[c[i].id - 1] = get0(c[i].y, c[i].z);
		}
	}

	for (int i=0; i<m; i++)
		cout << ans[i] << " \n"[i == m-1];
}