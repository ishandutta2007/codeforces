#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int h[100005];

const int MAXN = 131072;
int a[2*MAXN], b[2*MAXN];

void push(int x) {
	if (x < MAXN) {
		b[2*x] += b[x];
		b[2*x+1] += b[x];
	}
	a[x] += b[x];
	b[x] = 0;
}

void update(int l, int r, int v, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}

	if (l <= xl && xr <= r) {
		b[x] += v;
		push(x);
		return;
	}

	push(x);
	int xm = (xl+xr) >> 1;
	update(l, r, v, 2*x, xl, xm);
	update(l, r, v, 2*x+1, xm+1, xr);
	a[x] = min(a[2*x], a[2*x+1]);
}

int query(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	push(x);
	if (r < xl || xr < l)
		return 2e9;
	if (l <= xl && xr <= r)
		return a[x];
	int xm = (xl+xr) >> 1;
	return min(query(l, r, 2*x, xl, xm), query(l, r, 2*x+1, xm+1, xr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> h[i];

	for (int i=0; i<=n+1; i++) {
		update(i, i, h[i]+abs(i-1));
	}

	int sol = query(0, n+1);
	for (int i=2; i<=n; i++) {
		update(i, n+1, -1);
		update(0, i-1, 1);
		sol = max(sol, query(0, n+1));
	}

	cout << sol << '\n';
}