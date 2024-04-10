#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int b[262144];

void fadd(int x, int y) {
	while (x < 262144) {
		b[x] += y;
		x += x & -x;
	}
}

int fget(int x) {
	int y = 0;
	while (x > 0) {
		y += b[x];
		x -= x & -x;
	}
	return y;
}

int n, q;
int l[200005], r[200005];
int a[200005], inv[200005];

basic_string<int> occ[200005];
basic_string<int> qry[200005];
int ans[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		inv[a[i]] = i;
	}

	for (int i=1; i<=q; i++) {
		cin >> l[i] >> r[i];
		qry[r[i]] += i;
	}

	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j+=i) {
			int x = inv[i];
			int y = inv[j];
			if (x > y)
				swap(x, y);
			occ[y] += x;
		}
	}

	for (int i=1; i<=n; i++) {
		for (int x : occ[i]) {
			fadd(x, 1);
		}
		for (int j : qry[i]) {
			int lo = l[j];
			ans[j] = fget(n) - fget(lo-1);
		}
	}
	for (int i=1; i<=q; i++)
		cout << ans[i] << '\n';
}