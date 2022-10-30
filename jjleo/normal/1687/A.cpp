#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n, k;
ll a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]), a[i] += a[i - 1];
		if(k <= n){
			ll ans = 0;
			for(int i = k;i <= n;i++) ans = max(ans, a[i] - a[i - k]);
			printf("%lld\n", ans + 1ll * k * (k - 1) / 2);
			continue;
		}
		printf("%lld\n", a[n] + 1ll * (k - 1) * n - 1ll * n * (n - 1) / 2);
	}
}