#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
int n, k;
char s[maxn];
int f[maxn];
int sum[maxn];
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		ans = n;
		for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + (s[i] == '1');
		if(!sum[n]) ans = 0;
		for(int i = 1;i <= n;i++){
			f[i] = n;
			if(i - k >= 1) f[i] = min(f[i], f[i - k] + sum[i - 1] - sum[i - k]);
			f[i] = min(f[i], sum[i - 1]);
			f[i] += s[i] == '0';
			ans = min(ans, f[i] + sum[n] - sum[i]);
		}
		printf("%d\n", ans);
	}
}