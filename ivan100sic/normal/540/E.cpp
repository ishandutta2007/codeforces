#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[100005], b[100005];
int c[200005], ac[100005], bc[100005];
int d[200005];

int f[200005];

int fsum(int x) {
	x++;
	int z = 0;
	while (x) {
		z += f[x];
		x -= x & -x;
	}
	return z;
}

void fadd(int x, int y) {
	x++;
	while (x < 200005) {
		f[x] += y;
		x += x & -x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
		c[2*i] = a[i];
		c[2*i+1] = b[i];
	}
	sort(c, c+2*n);
	k = unique(c, c+2*n) - c;
	for (int i=0; i<n; i++) {
		ac[i] = lower_bound(c, c+k, a[i]) - c;
		bc[i] = lower_bound(c, c+k, b[i]) - c;
	}
	iota(d, d+k, 0);
	for (int i=0; i<n; i++)
		swap(d[ac[i]], d[bc[i]]);
	ll sol = 0;
	for (int i=0; i<k; i++) {
		sol += fsum(k+2) - fsum(d[i]);
		sol += abs(c[i] - c[d[i]]);
		sol -= abs(i - d[i]);
		fadd(d[i], 1);
	}

	cout << sol << '\n';
}