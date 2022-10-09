/*
	To the author of this task - in particular, the constraints (Time limit, N)
	Please do not problemset ever again.

	Thanks,
	Ivan (ivan100sic) Stosic
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[1000005], b[1000005], k;

int main() {
	scanf("%d%lld", &n, &k);
	for (int i=1; i<n; i++) {
		int p;
		ll w;
		scanf("%d%lld", &p, &w);
		a[i] = a[p-1] ^ w;
	}

	sort(a, a+n);

	ll sol = 0;

	for (int i=61; i>=0; i--) {
		for (int j=0; j<n; j++)
			b[j] = (a[j]^sol) >> i;
		sort(b, b+n);
		int l=0, r=0;
		ll z = 0;
		for (int j=0; j<n; j++) {
			ll y = a[j] >> i;
			while (l < n && b[l] < y)
				l++;
			while (r < n && b[r] <= y)
				r++;
			z += r-l;
		}

		if (z < k) {
			k -= z;
			sol |= 1ll << i;
		}
	}

	printf("%lld\n", sol);
}