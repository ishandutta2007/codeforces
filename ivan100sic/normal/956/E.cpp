#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct box {
	int x, t;
	bool operator< (const box& o) const {
		if (t != o.t)
			return t < o.t;
		return x > o.x;
	}
};

int hh;
int n, l, r;
box a[10005];
int d[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> r;
	for (int i=0; i<n; i++) {
		cin >> a[i].x;
		hh += a[i].x;
	}
	for (int i=0; i<n; i++)
		cin >> a[i].t;
	l = hh-l;
	r = hh-r;
	swap(l, r);
	sort(a, a+n);
	fill(d, d+hh, -123123123);
	d[0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=hh-a[i].x; j>=0; j--) {
			int k = a[i].x + j;
			int ok = a[i].t && l <= k && k <= r;
			d[k] = max(d[k], d[j] + ok);
		}
	}
	cout << *max_element(d, d+hh+1) << '\n';
}