#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

typedef long long ll;

int t;
int n;
int a[maxn], b[maxn];
ll f[maxn], g[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		for(int i = 1;i <= n;i++) f[i] = 0;
		for(int i = 2;i <= n;i++){
			for(int j = 1;j <= n;j++) g[j] = f[j];
			for(int j = i - 1;j;j--){
				if(a[j] != a[i]){
					g[j] = max(g[j], g[i] + abs(b[j] - b[i]));
					g[i] = max(g[i], f[j] + abs(b[j] - b[i]));
				}
			}
			for(int j = 1;j <= n;j++) f[j] = g[j];
		}
		ll ans = 0;
		for(int i = 1;i <= n;i++) ans = max(ans, f[i]);
		printf("%lld\n", ans);
	}
}