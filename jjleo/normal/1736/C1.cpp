#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), f[i] = n;
		int r = n;
		long long ans = 0;
		for(int i = n;i;i--){
			if(i - a[i] >= 1) f[i - a[i]] = min(f[i - a[i]], i - 1);
			r = min(r, f[i]);
			ans += r - i + 1;
		}
		printf("%lld\n", ans);
	}
}