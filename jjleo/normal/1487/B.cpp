#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if(k == 1){
			puts("1");
			continue;
		}
		if(n & 1){
			k--;
			int x = (n / 2 - 1) + 1;
			int ans = (1 + 1ll * (x + 1) * (k / x)) % n;
			ans += k % x;
			printf("%d\n", ans % n ? ans % n : n);
		}else{
			printf("%d\n", k % n ? k % n : n);
		}
	}
}