#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll am(ll k) {
	if (k == 0)return 0;
	ll q = n,ans=0;
	while (q) {
		ans += min(k, q);
		q -= min(k, q);
		q -= q / 10;
	}
	return ans;
}
int main() {
	scanf("%lld", &n);
	ll cur = 0,i;
	for (i = 1LL << 60; i; i >>= 1) {
		if (am(cur + i) * 2 < n)cur += i;
	}
	printf("%lld", cur + 1);
}