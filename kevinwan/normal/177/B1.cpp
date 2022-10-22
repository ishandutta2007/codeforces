#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n,i,ans=0;
	scanf("%lld", &n);
	ans = n;
	for (i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			n /= i;
			ans += n;
		}
	}
	if (n != 1)ans ++;
	printf("%lld", ans);
	getchar(); getchar();
}