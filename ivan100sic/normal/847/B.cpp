#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

template<int MAXN>
struct segtree {

	int a[2*MAXN];

	void init() {
		for (int i=1; i<=n; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = ::a[i];
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = max(a[2*i], a[2*i+1]);
		}
	}

	int get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return -1;
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return max(get(l, r, 2*node, nl, nm), get(l, r, 2*node+1, nm+1, nr));
	}

	void set(int pos, int val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = max(a[2*pos], a[2*pos+1]);
		}
	}
};

segtree<2 * 131072> drvo;

void brisi(int i) {
	drvo.set(i, -1);
}

int nadji_sledeceg(int x) {
	int val = a[x];
	int l = x+1;
	int r = n;
	int o = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (drvo.get(x+1, m) > val) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}

	return o;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	a[0] = -1;

	drvo.init();

	int used = 0;
	vector<vector<int>> sol;

	while (used < n) {
		vector<int> v;
		int x = 0;
		while (1) {
			int y = nadji_sledeceg(x);
			if (y == -1) {
				break;
			}
			x = y;
			brisi(y);
			v.push_back(a[y]);
			used++;

		}
		sol.push_back(v);
	}

	for (auto x : sol) {
		for (int y : x) {
			cout << y << ' ';
		}
		cout << '\n';
	}
}