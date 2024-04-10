#include <bits/stdc++.h>
#define maxn 14
#define maxm 105

using namespace std;

int n, m;
int x[maxn], y[maxn];

struct Quest{
	int x, y, t;
	
	inline bool operator < (const Quest &q) const {
		return t < q.t;
	}
}q[maxm];

int a[1 << maxn][maxn], b[1 << maxn][maxm];
int f[1 << maxn][maxm], g[1 << maxn][maxm];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) scanf("%d%d", &x[i], &y[i]);
	for(int i = 1;i <= m;i++) scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].t);
	sort(q + 1, q + 1 + m);
	for(int i = 0;i < (1 << n);i++){
		for(int j = 0;j < n;j++){
			a[i][j] = 1e9; 
			for(int k = 0;k < n;k++){
				if(i & (1 << k)) a[i][j] = min(a[i][j], abs(x[j] - x[k]) + abs(y[j] - y[k]));
			}
		}
	}
	for(int i = 0;i < (1 << n);i++){
		for(int j = 1;j <= m;j++){
			b[i][j] = 1e9; 
			for(int k = 0;k < n;k++){
				if(i & (1 << k)) b[i][j] = min(b[i][j], abs(q[j].x - x[k]) + abs(q[j].y - y[k]));
			}
		}
	}
	memset(f, -1, sizeof(f)), memset(g, 0x3f, sizeof(g));
	for(int i = 1;i <= m;i++) f[0][i] = 1;
	for(int i = 0;i < n;i++) g[1 << i][0] = 0;
	for(int i = 0;i < (1 << n);i++){
		//g -> f
		for(int j = 0;j <= m;j++){
			for(int k = j + 1;k <= m;k++){
				if(g[i][j] + b[i][k] <= q[k].t) f[i][k] = max(f[i][k], j + 1);
			}
		}
		// f -> f
		for(int j = 1;j <= m;j++){
			if(f[i][j] == -1) continue;
			for(int k = j + 1;k <= m;k++){
				if(q[j].t + min(abs(q[j].x - q[k].x) + abs(q[j].y - q[k].y), b[i][k]) <= q[k].t){
					f[i][k] = max(f[i][k], f[i][j] + 1);
				}
			}
		}
		//f -> g
		for(int j = 1;j <= m;j++){
			if(f[i][j] == -1) continue;
			for(int k = 0;k < n;k++){
				if(i & (1 << k)) continue;
				g[i | (1 << k)][f[i][j]] = min(g[i | (1 << k)][f[i][j]], q[j].t + min(abs(q[j].x - x[k]) + abs(q[j].y - y[k]), a[i][k]));
			}
		}
		//g -> g
		for(int j = 0;j <= m;j++){
			for(int k = 0;k < n;k++){
				if(i & (1 << k)) continue;
				g[i | (1 << k)][j] = min(g[i | (1 << k)][j], g[i][j] + a[i][k]);
			} 
		}
	}
	int ans = 0;
	for(int i = 0;i < (1 << n);i++) for(int j = 1;j <= m;j++) ans = max(ans, f[i][j]);
	printf("%d", ans);
}