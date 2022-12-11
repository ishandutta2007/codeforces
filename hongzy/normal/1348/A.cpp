#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		int n; scanf("%d", &n);
		ll ans = 0;
		for(int i = 1; i <= n / 2; i ++) {
			ans += 1ll << i;
		}
		printf("%lld\n", ans);
	}	
	return 0;
}