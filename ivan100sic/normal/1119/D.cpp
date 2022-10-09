#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
ll s[100005];
ll d[100005], z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];
	sort(s, s+n);
	for (int i=0; i<n-1; i++)
		d[i] = s[i+1] - s[i];
	sort(d, d+n-1);
	partial_sum(d, d+n-1, z+1);
	cin >> q;
	while (q--) {
		ll l, r;
		cin >> l >> r;
		r = r-l+1;
		auto it = lower_bound(d, d+n-1, r) - d;
		cout << n*r - (it * r - z[it]) << ' ';
	}
	cout << '\n';
}