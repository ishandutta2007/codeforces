#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, h, m;
int a[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h >> m;
	for (int i=1; i<=n; i++)
		a[i] = h;
	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		for (int i=l; i<=r; i++)
			a[i] = min(a[i], x);
	}
	cout << inner_product(a+1, a+n+1, a+1, 0) << '\n';
}