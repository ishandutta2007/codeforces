#include <bits/stdc++.h>
#define maxn 1000086
using namespace std;

int p[maxn];
bool vis[maxn];
int num[maxn], cnt;
int sum[maxn];
int ans;
int a[maxn], tot;

void dfs(int i, int x){
	vis[i] = true, ++num[x];
	if(!vis[p[i]]) dfs(p[i], x);
}

int n, k;
bitset<maxn> b;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &p[i]);
	for(int i = 1;i <= n;i++) if(!vis[i]) dfs(i, ++cnt);
	for(int i = 1;i <= cnt;i++) ++sum[num[i]];
	for(int i = 1;i <= n;i++){
		if(!sum[i]) continue;//debug:0tle 
		int j = 1, x = sum[i];
		while(x - j > 0) x -= j, a[++tot] = i * j, j <<= 1;
		a[++tot] = i * x;
	} 
	b[0] = 1;
	for(int i = 1;i <= tot;i++) b |= b << a[i];
	printf("%d ", b[k] ? k : k + 1);
	
	for(int i = 1;i <= cnt;i++) ans += num[i] / 2;//, printf("%d--\n", num[i]);
	if(ans > k) ans = k;
	printf("%d", min(n, ans * 2 + (k - ans)));
}