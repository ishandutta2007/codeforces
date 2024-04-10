#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], b[maxn];
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = n * 100;~j;j--){
				f[j] = 0;
				if(j - a[i] >= 0) f[j] |= f[j - a[i]];
				if(j - b[i] >= 0) f[j] |= f[j - b[i]];
			}
		}
		int sum = 0;
		for(int i = 1;i <= n;i++) sum += a[i] + b[i];
		int ans = 1e9;
		for(int i = 0;i <= n * 100;i++) if(f[i]) ans = min(ans, (i * i + (sum - i) * (sum - i)));
		for(int i = 1;i <= n;i++) ans += (n - 2) * a[i] * a[i] + (n - 2) * b[i] * b[i];
		printf("%d\n", ans);
	}
}