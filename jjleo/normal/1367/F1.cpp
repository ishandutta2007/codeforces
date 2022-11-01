#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

int t;
int n, n0;
int a[maxn], b[maxn];
int f[maxn][3];
int g[maxn], h[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]), b[i] = a[i], g[i] = 0;
			memset(f[i], 0, sizeof(f[i]));
		}
		sort(b + 1, b + 1 + n);
		n0 = unique(b + 1, b + 1 + n) - (b + 1);
		for(int i = 1;i <= n;i++){
			a[i] = lower_bound(b + 1, b + 1 + n0, a[i]) - b;
			if(!g[a[i]]) g[a[i]] = i;
			h[a[i]] = i;
		}
		for(int i = 1;i <= n;i++){
			f[a[i]][0]++;
			if(g[a[i]] == i){
				f[a[i]][1] = max(f[a[i]][1], f[a[i] - 1][0] + 1);
				if(h[a[i] - 1] < i) f[a[i]][1] = max(f[a[i]][1], f[a[i] - 1][1] + 1);
			}else{
				f[a[i]][1]++;
			}
			f[a[i]][2]++;
			f[a[i]][2] = max(f[a[i]][2], f[a[i] - 1][0] + 1);
			if(h[a[i] - 1] < i) f[a[i]][2] = max(f[a[i]][2], f[a[i] - 1][1] + 1);
			//printf("%d %d %d %d--\n", a[i], f[a[i]][0], f[a[i]][1], f[a[i]][2]);
		}
		int ans = 0;
		for(int i = 1;i <= n0;i++) ans = max(ans, max(f[i][0], f[i][2]));
		printf("%d\n", n - ans);
	}
}