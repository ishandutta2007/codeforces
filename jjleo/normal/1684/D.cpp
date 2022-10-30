#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		long long ans = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), ans += a[i], a[i] -= n - i;
		sort(a + 1, a + 1 + n, greater<int>());
		long long sum = 0, val = 0;
		for(int i = 1;i <= k;i++) val += a[i], sum = max(sum, val + 1ll * i * (i - 1) / 2);
		printf("%lld\n", ans - sum);
	}
}