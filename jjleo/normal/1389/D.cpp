#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
int l1, r1, l2, r2;
long long sum, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if(l2 <= l1 && r1 <= r2) swap(l1, l2), swap(r1, r2);
		sum = ans = 0;
		if(l1 <= l2 && r2 <= r1){
			sum = 1ll * (r2 - l2) * n;
			if(sum >= k){
				puts("0");
				continue;
			} 
			int x = (r1 - l1) - (r2 - l2);
			ans += min(k - sum, 1ll * x * n);
			sum += ans;
			if(sum < k) ans += (k - sum) * 2;
			printf("%lld\n", ans);
		}else{
			if(l1 > l2) swap(l1, l2), swap(r1, r2);
			if(r1 <= l2){
				int y = l2 - r1;
				int x = r2 - l1;
				ans = y + min(k - sum, 1ll * x);
				sum += min(k - sum, 1ll * x);
				if(sum < k) ans += (k - sum) * 2;
				sum = 0;
				long long ans1 = 0;
				sum += min(k / x, n) * x;
				ans1 += min(k / x, n) * (x + y);
				n -= min(k / x, n);
				//printf("%d--\n", k);
				if(n){
					if(sum) ans1 += min(y + (k - sum), (k - sum) * 2);
					else ans1 += y + (k - sum);
				}
				else ans1 += (k - sum) * 2;
				printf("%lld\n", min(ans, ans1));
			}else{
				sum = 1ll * (r1 - l2) * n;
				if(sum >= k){
					puts("0");
					continue;
				}
				int x = (r2 - r1) + (l2 - l1);
				ans += min(k - sum, 1ll * x * n);
				sum += ans;
				if(sum < k) ans += (k - sum) * 2;
				printf("%lld\n", ans);
			}
		}
	}
}