#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n, a, b;
int x[maxn];
ll sum[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 1;i <= n;i++) scanf("%d", &x[i]), sum[i] = sum[i - 1] + x[i];
		ll ans = sum[n] * b, val = 0;
		for(int i = 1;i <= n;i++){
			val += 1ll * (a + b) * (x[i] - x[i - 1]);
			ans = min(ans, val + (sum[n] - sum[i] - 1ll * (n - i) * x[i]) * b);
		}
		printf("%lld\n", ans);
	}
}