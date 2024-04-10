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

int n;
int a[100005];

const int MAXN = 131072;

struct tree {

	int mx[2*MAXN], lazy[2*MAXN];

	void init() {
		memset(mx, 0, sizeof(mx));
		memset(lazy, 0, sizeof(lazy));
	}

	void push(int node) {
		if (node < MAXN) {
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		mx[node] += lazy[node];
		lazy[node] = 0;
	}

	void add(int l, int r, int val, int node = 1, int nl = 1, int nr = MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			lazy[node] += val;
			push(node);
			return;
		}

		int m = (nl+nr) >> 1;
		add(l, r, val, 2*node, nl, m);
		add(l, r, val, 2*node+1, m+1, nr);

		mx[node] = max(mx[2*node], mx[2*node+1]);
	}

	int get(int l, int r, int node = 1, int nl = 1, int nr = MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return -1e9;
		}
		if (l <= nl && nr <= r) {
			return mx[node];
		}

		int m = (nl+nr) >> 1;
		int v1 = get(l, r, 2*node, nl, m);
		int v2 = get(l, r, 2*node+1, m+1, nr);

		return max(v1, v2);
	}

};

tree drvo;

int seek() {

	if (drvo.get(1, n) <= 0) {
		return -1;
	}

	int l=1, r=n, o=-1;

	while (l <= r) {
		int m = (l+r) >> 1;

		if (drvo.get(m, n) > 0) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}

	return a[o];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int p, t, x;
		cin >> p >> t;
		if (t == 1) {
			cin >> x;
			a[p] = x;
			drvo.add(1, p, 1);
		} else {
			drvo.add(1, p, -1);
		}

		// odgovori
		cout << seek() << '\n';
	}

}