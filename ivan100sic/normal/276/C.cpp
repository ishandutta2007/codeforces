#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
ll a[200005], z[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	while (q--) {
		int l, r;
		cin >> l >> r;
		z[l]++;
		z[r+1]--;
	}
	for (int i=1; i<=n; i++)
		z[i] += z[i-1];
	sort(a+1, a+n+1);
	sort(z+1, z+n+1);
	cout << inner_product(a+1, a+n+1, z+1, 0ll) << '\n';
}