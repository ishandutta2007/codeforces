#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

int n, m, k;
char s[25], t[25];
int a[maxn], b[maxn];
int f[maxn], g[maxn];
int x, y;
int p[maxn];

int main(){
	scanf("%d%d%d%s%s", &n, &m, &k, s + 1, t + 1);
	memset(f, 0x3f, sizeof(f)), memset(g, -0x3f, sizeof(g));
	for(int i = 1;i <= k;i++) p[i] = i;
	for(int i = 0;i <= n;i++){
		if(i){
			scanf("%d%d", &x, &y);
			int xx, yy;
			for(int j = 1;j <= k;j++){
				if(p[j] == x) xx = j;
				if(p[j] == y) yy = j;
			}
			swap(p[xx], p[yy]);
			//printf("%d %d--\n", xx, yy);
		}
		for(int j = 0;j < k;j++){
			if(s[p[j + 1]] == '1') a[i] += 1 << j;
			if(t[p[j + 1]] == '1') b[i] += 1 << j;
		}
		f[a[i]] = min(f[a[i]], i), g[b[i]] = max(g[b[i]], i);
	}
	for(int j = 0;j < k;j++){
		for(int i = 0;i < (1 << k);i++){
			if(!(i & (1 << j))){
				f[i] = min(f[i], f[i ^ (1 << j)]);
				g[i] = max(g[i], g[i ^ (1 << j)]);
			}
		}
	}
	int l, r, ans = -1;
	for(int i = 0;i < (1 << k);i++){
		//printf("%d %d %d %d--\n", i, f[i], g[i], g[i] - f[i] >= m);
		if(g[i] - f[i] >= m && __builtin_popcount(i) > ans) ans = __builtin_popcount(i), l = f[i] + 1, r = g[i];
	}
	ans = (ans << 1) + k;
	for(int i = 1;i <= k;i++) ans -= s[i] + t[i] - 2 * '0';
	printf("%d\n%d %d", ans, l, r);
	
}