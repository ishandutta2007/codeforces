#include <bits/stdc++.h>
#define mod(a,b) (a>=0?(a%b):(b-a%b))
using namespace std;
typedef long long ll;
bool p(ll x) {
	for (ll i = 2; i*i <= x; i++)if (x%i == 0)return 0;
	return 1;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if (a > b + 1) { printf("NO\n"); continue; }
		if (p(a + b))printf("YES\n");
		else printf("NO\n");
	}
	getchar(); getchar();
}