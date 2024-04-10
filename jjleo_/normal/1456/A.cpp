#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, p, k, x, y;
char s[maxn];
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &p, &k);
		scanf("%s%d%d", s + 1, &x, &y);
		for(int i = 0;i < k;i++) f[i] = 0;
		for(int i = p;i <= n;i++){
			f[i % k] += s[i] == '0';
		}
		long long ans = 2e9;
		for(int i = p;i <= n;i++){
			ans = min(ans, 1ll * (i - p) * y + 1ll * f[i % k] * x);
			f[i % k] -= s[i] == '0';
		}
		printf("%lld\n", ans);
	}
}