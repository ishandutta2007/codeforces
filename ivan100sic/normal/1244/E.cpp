// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, k, a[100005], z[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);

	ll l=0, r=n-1;
	ll gap = a[n-1] - a[0];
	while (l < r) {
		ll cl = l+1, cr = n-r;
		ll gl = a[l+1] - a[l], gr = a[r] - a[r-1];

		bool sw = 0;
		if (cl > cr)
			swap(cl, cr), swap(gl, gr), sw = 1;

		if (cl * gl <= k) {
			k -= cl * gl;
			sw ? r-- : l++;
			gap -= gl;
		} else {
			gap -= k / cl;
			break;
		}
	}

	cout << gap << '\n';
}