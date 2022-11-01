#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		ll ans = 1e18, sum = 0, mn1 = 1e18, mn2 = 1e18;
		int x = n, y = n;
		for(int i = 1;i <= n;i++){
			if(i & 1) mn1 = min(mn1, 1ll * a[i]), x--, sum += a[i];
			else mn2 = min(mn2, 1ll * a[i]), y--, sum += a[i];
			if(i > 1) ans = min(ans, sum + x * mn1 + y * mn2);
		}
		printf("%lld\n", ans);
	}
}