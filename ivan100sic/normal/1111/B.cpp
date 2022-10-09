#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, m, k;
ll a[100005], z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	partial_sum(a, a+n, z+1);
	ld val = 0.0;
	for (int i=0; i<n; i++) {
		if (i > m)
			break;
		val = max(val, (ld)(z[n] - z[i] + min(m-i, (n-i)*k)) / (n-i));
	}
	cout.precision(20);
	cout << fixed;
	cout << val << '\n';
}