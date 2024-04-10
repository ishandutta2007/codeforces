#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

typedef long long ll;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n < 5){
			puts("0");
			continue;
		}
		ll l = 1, r = 1e9, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			ll c = 2 * mid + 1;
			if(c * c - (c * c - 1) / 2 <= n) l = mid;
			else r = mid - 1;
		}
		printf("%lld\n", l);
	}
	/*int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			for(int k = j;k <= n;k++){
				if(i * i + j * j == k * k && i * i - j == k) printf("%d %d %d--\n", i, j, k);
			}
		}
	}	
	printf("%d", ans);*/
}