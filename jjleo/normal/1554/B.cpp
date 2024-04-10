#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		long long ans = -1e18;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = max(1, n - 200);i <= n;i++){
			for(int j = 1;j < i;j++) ans = max(ans, 1ll * i * j - k * (a[i] | a[j]));
		}
		printf("%lld\n", ans);
	}
}