#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[100005], b[100005];
ll w[100005], z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	copy(a, a+n, b);
	sort(b, b+n);
	partial_sum(a, a+n, w+1);
	partial_sum(b, b+n, z+1);
	int q;
	cin >> q;
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		auto d = t == 1 ? w : z;
		cout << d[r] - d[l-1] << '\n';
	}
}