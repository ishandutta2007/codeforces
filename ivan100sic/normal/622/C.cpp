#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[200005], p[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] == a[i-1]) {
			p[i] = p[i-1];
		} else {
			p[i] = i-1;
		}
	}
	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		if (a[r] != x) {
			cout << r << '\n';
		} else {
			int y = p[r];
			cout << (y >= l ? y : -1) << '\n';
		}
	}
}