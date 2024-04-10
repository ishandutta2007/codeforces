#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int a[100005], b[100005], c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = i;
		if (i > 1 && a[i-1] >= a[i])
			b[i] = b[i-1];
	}

	for (int i=n; i>=1; i--) {
		c[i] = i;
		if (i < n && a[i] <= a[i+1])
			c[i] = c[i+1];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		r = b[r];
		l = c[l];
		if (l >= r) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

}