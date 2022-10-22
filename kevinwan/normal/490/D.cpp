#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	while (b)a %= b, a ^= b ^= a ^= b;
	return a;
}
int main() {
	ll a[2], b[2],c,d;
	scanf("%lld%lld%lld%lld", a,a+1,b,b+1);
	int aaa=0, bbb=0,ans=0,i;
	c = a[0] * a[1], d = b[0] * b[1];
	while (!(c % 3)) c /= 3, aaa++;
	while (!(d % 3)) d /= 3, bbb++;
	for (; aaa > bbb; aaa--) {
		if (a[0] % 3 == 0)a[0] /= 3, a[0] *= 2;
		else if (a[1] % 3 == 0)a[1] /= 3, a[1] *= 2;
		ans++;
	}
	for (; bbb > aaa; bbb--) {
		if (b[0] % 3 == 0)b[0] /= 3, b[0] *= 2;
		else if (b[1] % 3 == 0)b[1] /= 3, b[1] *= 2;
		ans++;
	}
	aaa = 0, bbb = 0;
	c = a[0] * a[1], d = b[0] * b[1];
	while (!(c % 2)) c /= 2, aaa++;
	while (!(d % 2)) d /= 2, bbb++;
	for (; aaa > bbb; aaa--) {
		if (a[0] % 2 == 0)a[0] /= 2;
		else if (a[1] % 2 == 0)a[1] /= 2;
		ans++;
	}
	for (; bbb > aaa; bbb--) {
		if (b[0] % 2 == 0)b[0] /= 2;
		else if (b[1] % 2 == 0)b[1]/=2;
		ans++;
	}
	if (a[0] * a[1] != b[0] * b[1])printf("-1");
	else printf("%d\n%lld %lld\n%lld %lld", ans, a[0], a[1], b[0], b[1]);
	getchar(); getchar();
}