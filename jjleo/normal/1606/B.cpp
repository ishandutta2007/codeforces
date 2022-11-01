#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &n, &k);
		if(n == 1){
			puts("0");
			continue;
		}
		ll x = 1;
		ll ans = 0;
		while(x <= k && x < n){
			ans++;
			x *= 2;
		}
		ans += (n - x + k - 1) / k;
		printf("%lld\n", ans);
	}
}