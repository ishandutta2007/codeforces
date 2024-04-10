#include <bits/stdc++.h>
#define maxn 4005
using namespace std;

int n;
int c[maxn], r[maxn];
int a[maxn], n0;
vector<int> v[maxn];
int f[maxn][maxn], g[maxn][maxn], h[maxn][maxn];

void dfs(int i, int j){
	if(g[i][j]) printf("%d ", g[i][j]);
	if(i == h[i][j] || j == h[i][j]) return;
	//printf("%d %d %d--\n", i, j, h[i][j]);
	dfs(i, h[i][j]), dfs(h[i][j], j);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d", &c[i], &r[i]), a[++n0] = c[i] + r[i], a[++n0] = c[i] - r[i];
	sort(a + 1, a + 1 + n0);
	n0 = unique(a + 1, a + 1 + n0) - (a + 1);
	for(int i = 1;i <= n;i++){
		int x = lower_bound(a + 1, a + 1 + n0, c[i] - r[i]) - a, y = lower_bound(a + 1, a + 1 + n0, c[i] + r[i]) - a;
		v[x].push_back(y), g[x][y] = i;
		//printf("%d %d--\n", x, y);
	}
	for(int i = 1;i <= n0;i++) sort(v[i].begin(), v[i].end());
	for(int l = 1;l <= n0;l++){
		for(int i = 1;i + l - 1 <= n0;i++){
			int sum = f[i + 1][i + l - 1] + (g[i][i + l - 1] > 0);
			h[i][i + l - 1] = i + 1;
			for(int j = 0;j < v[i].size() && v[i][j] <= i + l - 1;j++){
				if(sum < f[i][v[i][j]] + f[v[i][j]][i + l - 1] + (g[i][i + l - 1] > 0)){
					sum = f[i][v[i][j]] + f[v[i][j]][i + l - 1] + (g[i][i + l - 1] > 0);
					h[i][i + l - 1] = v[i][j];
				}
				//printf("%d %d %d %d--\n", i, i + l - 1, v[i][j], f[i][i + l - 1]);
			}
			f[i][i + l - 1] = sum;
			//printf("%d %d %d--\n", i, i + l - 1, h[i][i + l - 1]);
		}
	}
	printf("%d\n", f[1][n0]);
	dfs(1, n0);
	
}