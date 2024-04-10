#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n;
ll k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &k);
		ll sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i];
		if(sum <= k){
			puts("0");
			continue;
		}
		if(n == 1){
			printf("%lld\n", a[1] - k);
			continue;
		}
		sort(a + 1, a + 1 + n);
		ll ans = sum - k, val = 0;
		for(int i = 1;i < n;i++){
			val += a[n - i + 1];
			ans = min(ans, max(0ll, ((sum - k) - (val - 1ll * i * a[1]) + i) / (i + 1)) + i);
		}
		printf("%lld\n", ans);
	}
}