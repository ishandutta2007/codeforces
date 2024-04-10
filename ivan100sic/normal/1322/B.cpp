#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[400005];
int q[400005];

ll lespar(int lim) {
	int j = 0;
	ll u = 0;
	for (int i=0; i<n; i++) {
		// a[i] + a[j] < B
		while (j < n && q[i] + a[j] < lim)
			j++;
		u += j;
	}
	for (int i=0; i<n; i++)
		if (a[i] + a[i] < lim)
			u--;
	u /= 2;
	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int sol = 0;
	for (int b=25; b>=0; b--) {
		int B = 1 << b;
		for (int i=0; i<n; i++)
			a[i] &= 2*B-1;
		sort(a, a+n);
		copy(a, a+n, q);
		reverse(q, q+n);
		ll t = lespar(4*B) - lespar(3*B) + lespar(2*B) - lespar(B);
		// cerr << "bit " << b << ": " << u << '\n';
		sol ^= (t % 2) << b;

	}
	cout << sol << '\n';
}