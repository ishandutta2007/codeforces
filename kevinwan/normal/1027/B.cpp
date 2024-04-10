#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n; int q,i;
	scanf("%lld%d", &n, &q);
	for (i = 0; i < q; i++) {
		if (n % 2) {
			ll a, b, k;
			scanf("%lld%lld", &a, &b);
			k = (a - 1)*n + b - 1;
			if (k % 2 == 0)printf("%lld\n", k / 2 + 1);
			else printf("%lld\n", k / 2 + (n*n + 1) / 2 + 1);
		}
		else {
			ll a, b;
			scanf("%lld%lld", &a, &b);
			a--, b--;
			if ((a + b) % 2 == 0)printf("%lld\n", a*n / 2 + b / 2+1);
			else printf("%lld\n", a*n / 2 + b / 2 + n * n / 2 + 1);
		}
	}
	getchar(); getchar();
}