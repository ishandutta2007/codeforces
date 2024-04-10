	#include <bits/stdc++.h>
	#define maxn 100086
	
	using namespace std;
	
	typedef long long ll;
	
	int n, q;
	int a[maxn];
	int opt, x;
	ll k;
	
	int main(){
		scanf("%d%d", &n, &q);
		for(int i = 0;i < n;i++) scanf("%d", &a[i]);
		while(q--){
			scanf("%d%d%lld", &opt, &x, &k);
			if(opt == 1){
				a[x] = k;
			}else{
				ll sum = 0, small = 0;
				for(int i = 0;i < n;i++) sum += 1ll * (1 << i) * a[i];
				if(sum < k){
					puts("-1");
					continue;
				}
				for(int i = 0;i <= x;i++) k -= a[i];
				if(k <= 0){
					puts("0");
					continue;
				}
				sum = 0;
				for(int i = 0;i <= x;i++) small += 1ll * ((1 << i) - 1) * a[i];
				int i;
				for(i = x + 1;i < n;i++){
					ll val = 1 << (i - x);
					ll need = min(k / val, 1ll * a[i]);
					k -= need * val;
					sum += need * (val - 1);
					small += need * val * ((1 << x) - 1);
					if(need != a[i]) break;//debug  
				}
				if(!k){
					printf("%lld\n", sum);
					continue;
				}
				if(i == n){
					printf("%lld\n", sum + k);
					continue;
				}
				ll ans = 1e18;
				if(small >= k) ans = min(ans, sum + k);
				for(--i;i >= x;i--){//debugsmall 
					sum++;
					ll val = 1 << (i - x);
					if(val <= k){
						k -= val;
						sum += val - 1;
						small += val * ((1 << x) - 1);
					}
					if(small >= k) ans = min(ans, sum + k);
				}
				printf("%lld\n", ans);
			}
		}
	}