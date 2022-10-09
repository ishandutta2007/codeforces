#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int nx[200005], n, k;
int a[200005];

ll safemul(ll x, ll y) {
	if (x * 1.0 * y > 4e18)
		return 4e18;
	return x*y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	nx[n+1] = n+1;
	for (int i=n; i>=1; i--) {
		nx[i] = nx[i+1];
		if (a[i] >= 2)
			nx[i] = i;
	}
	ll z = 0;
	for (int i=1; i<=n; i++) {
		int j = i;
		ll prod = a[i], sum = a[i];
		if (prod == k*sum)
			z++;
		while (1) {
			int jj = nx[j+1];
			int l = jj - j - 1;
			if ((prod - k*sum) % k == 0) {
				ll t = (prod - k*sum) / k;
				if (1 <= t && t <= l) {
					z++;
				}
			}
			if (jj == n+1)
				break;
			prod = safemul(prod, a[jj]);
			sum += l + a[jj];
			if (prod > 3e18)
				break;
			if (prod == k*sum)
				z++;
			j = jj;
		}
	}
	cout << z << '\n';
}