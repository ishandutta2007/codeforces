#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, ans = 0;
	scanf("%lld", &n);
	ll i;
	for (i = 1; i <= n; i <<= 1) {
		ans += (n+i-1) / (i * 2)*i;
	}
	printf("%lld", ans);
	getchar(); getchar();
}