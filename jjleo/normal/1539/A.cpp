#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int k, n, x, t;

int main(){
	scanf("%d", &k);
	while(k--){
		scanf("%d%d%d", &n, &x, &t);
		int val = t / x;
		val = min(val, n - 1);
		long long ans = 1ll * val * n;
		ans -= 1ll * val * (val + 1) / 2;
		printf("%lld\n", ans);
	}	
}