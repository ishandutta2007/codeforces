#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

int n, m, k;
int a[maxn], b[maxn], c[maxn];
int d[maxn];
vector<int> v[maxn];
int x, y;
int f[2][maxn];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= n;i++) scanf("%d%d%d", &a[i], &b[i], &c[i]), d[i] = i;
	while(m--){
		scanf("%d%d", &x, &y);
		d[y] = max(d[y], x);
	}
	for(int i = 1;i <= n;i++) v[d[i]].push_back(i);
	memset(f, -0x3f, sizeof(f));
	f[0][k] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = a[i];j + b[i] < maxn;j++) f[1][j + b[i]] = f[0][j];
		for(int y = 0;y < v[i].size();y++){
			x = c[v[i][y]];
			for(int j = 0;j < maxn - 1;j++) f[1][j] = max(f[1][j], f[1][j + 1] + x);
		}
		memcpy(f[0], f[1], sizeof(f[1]));
		memset(f[1], -0x3f, sizeof(f[1]));
	}
	int ans = -1;
	for(int i = 0;i < maxn;i++) ans = max(ans, f[0][i]);
	printf("%d", ans);
}