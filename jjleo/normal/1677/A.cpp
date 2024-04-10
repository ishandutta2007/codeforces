#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

typedef long long ll;

int t, n;
int f[maxn][maxn], g[maxn][maxn];
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 0;i <= n + 1;i++) for(int j = 1;j <= n;j++) f[i][j] = g[i][j] = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) f[i][j] = f[i - 1][j];
			for(int j = a[i];j <= n;j++) f[i][j]++;
		}
		for(int i = n;i;i--){
			for(int j = 1;j <= n;j++) g[i][j] = g[i + 1][j];
			for(int j = a[i];j <= n;j++) g[i][j]++;
		}
		ll ans = 0;
		for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++){
			ans += f[i - 1][a[j] - 1] * g[j + 1][a[i] - 1];
		}
		printf("%lld\n", ans);
	}
}