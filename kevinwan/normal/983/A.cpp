#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	while (b) { a %= b; a ^= b ^= a ^= b; }
	return a;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		ll a, b, c,bb;
		scanf("%lld%lld%lld", &a, &b, &c);
		b /= gcd(a, b);
		while(1){
			ll t= gcd(b, c);
			b/=t;
			c=t;
			if(c==1)break;
		}
		if (b == 1)printf("Finite\n");
		else printf("Infinite\n");
	}
	getchar(); getchar();
}