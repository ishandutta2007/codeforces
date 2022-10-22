#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll gcd(ll a, ll b) {
	while (b) { a %= b; a ^= b ^= a ^= b; }
	return a | b;
}
int main() {
	ll a, b, x,y;
	scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
	if (y%x != 0) {
		printf("0");
		return 0;
	}
	y /= x;
	a = (a - 1) / x + 1;
	b /= x;
	int ans = 0;
	for (ll i = 1; i*i <= y; i++) {
		if (y%i)continue;
		if (gcd(i, y / i) != 1)continue;
		if (i >= a && i <= b&& y / i >= a && y / i <= b)ans+=1+(i*i!=y);
	}
	printf("%d", ans);
	getchar(); getchar();
}