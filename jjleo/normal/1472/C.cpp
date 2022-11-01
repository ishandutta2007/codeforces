#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
long long f[maxn], ans;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), f[i] = 0;
		ans = 0;
		for(int i = 1;i <= n;i++){
			f[i] += a[i];
			if(i + a[i] <= n) f[i + a[i]] = max(f[i], f[i + a[i]]);
			ans = max(ans, f[i]);
		}
		printf("%lld\n", ans);
	}
}