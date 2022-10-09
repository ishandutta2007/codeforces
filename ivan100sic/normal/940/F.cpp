#include <bits/stdc++.h>
using namespace std;

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

struct query {
	int t, x, y;
};

static int n, qc;
static int a0[100005], a[100005], ans[100005];
static query q[100005];

static int tl, tr;
static int c[200005];
static int d[100005];

static void reset() {
	memset(c, 0, sizeof c);
	memset(d, 0, sizeof d);
	memcpy(a, a0, sizeof a);
	tl = 1;
	tr = 0;
}

static void rm(int x) {
	d[c[x]]--;
	c[x]--;
	d[c[x]]++;
}

static void ad(int x) {
	d[c[x]]--;
	c[x]++;
	d[c[x]]++;
}

static void walk(int l, int r) {
	while (tr < r) ad(a[++tr]);
	while (tl > l) ad(a[--tl]);
	while (tr > r) rm(a[tr--]);
	while (tl < l) rm(a[tl++]);
}

static int val() {
	for (int i=1; i<=700; i++)
		if (d[i] == 0)
			return i;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> qc;
	compressor cmpr;
	for (int i=1; i<=n; i++) {
		cin >> a0[i];
		cmpr.add(a0+i);
	}

	for (int i=0; i<qc; i++) {
		cin >> q[i].t >> q[i].x >> q[i].y;
		if (q[i].t == 2)
			cmpr.add(&q[i].y);
	}

	cmpr.run();

	for (int u=0; u<50; u++) {
		for (int v=u; v<50; v++) {
			reset();
			for (int i=0; i<qc; i++) {
				if (q[i].t == 2) {
					if (tl <= q[i].x && q[i].x <= tr) {
						rm(a[q[i].x]);
						a[q[i].x] = q[i].y;
						ad(a[q[i].x]);
					} else {
						a[q[i].x] = q[i].y;
					}
				} else if ((q[i].x >> 11) == u && (q[i].y >> 11) == v) {
					walk(q[i].x, q[i].y);
					ans[i] = val();
				}
			}
		}
	}

	for (int i=0; i<qc; i++)
		if (q[i].t == 1)
			cout << ans[i] << '\n';
}