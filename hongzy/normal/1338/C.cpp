#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll A[] = {0, 2, 3, 1};
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		ll n; scanf("%lld", &n); n --;
		ll nn = n / 3, x = 1;
		while(nn >= x) { nn -= x; x *= 4; }
		ll u = x + nn, v = x * 2;
		for(int i = 0; (1ll << i) <= nn; i += 2) v += A[nn >> i & 3] << i;
		printf("%lld\n", n % 3 == 0 ? u : (n % 3 == 1 ? v : (u ^ v)));
	}
	return 0;
}