#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);
	if (k < n) {
		printf("%lld 1", k + 1);
		return 0;
	}
	k -= n;
	ll up = k / (m - 1);
	k %= m - 1;
	if (up % 2 == 0)printf("%lld %lld", n - up, 2 + k);
	else printf("%lld %lld", n - up, m - k); 
}