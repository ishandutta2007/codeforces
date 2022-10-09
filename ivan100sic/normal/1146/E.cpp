#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct func {
	int a, b;

	func() : a(1), b(-1) {}

	func(int _a, int _b) : a(_a), b(_b) {}

	int operator[] (int x) const {
		if (x < 0)
			return b;
		else
			return a;
	}

	func operator+ (const func& q) const {
		func tmp;
		tmp.a = q[a];
		tmp.b = q[b];
		return tmp;
	}
};

const int MAXN = 131072;
func b[2*MAXN];
	
void push(int x) {
	if (x < MAXN) {
		b[2*x] = b[2*x] + b[x];
		b[2*x+1] = b[2*x+1] + b[x];
		b[x] = func();
	}
}

void update(int l, int r, func f, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}
	if (l <= xl && xr <= r) {
		b[x] = b[x] + f;
		push(x);
		return;
	}
	push(x);
	int xm = (xl+xr) >> 1;
	update(l, r, f, 2*x, xl, xm);
	update(l, r, f, 2*x+1, xm+1, xr);
	// nista
}

int n, q;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	while (q--) {
		char t;
		int x;
		cin >> t >> x;
		int ax = abs(x);
		if (t == '>') {
			if (x >= 0) {
				update(ax+1, MAXN-1, func(-1, -1));
			} else {
				update(1, ax-1, func(-1, 1));
				update(ax, MAXN-1, func(-1, -1));
			}
		} else {
			if (x <= 0) {
				update(ax+1, MAXN-1, func(1, 1));
			} else {
				update(1, ax-1, func(-1, 1));
				update(ax, MAXN-1, func(1, 1));
			}
		}
	}

	for (int i=1; i<MAXN; i++)
		push(i);

	// for (int i=1; i<2*MAXN; i++)
	// 	cerr << i << ' ' << b[i][-1] << ' ' << b[i][1] << '\n';

	for (int i=0; i<n; i++) {
		cout << abs(a[i]) * b[abs(a[i])+MAXN][a[i]] << " \n"[i == n-1];
	}

}