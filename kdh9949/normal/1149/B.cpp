#include <bits/stdc++.h>
using namespace std;

const int M = 100005, N = 1005, K = 26;

int n, q, nx[M][K], p[3][N], wh[N][3], c[3], ans[N];
char s[M], t[3][N];
vector<int> d[N][N];

int main(){
	scanf("%d%d%s", &n, &q, s + 1);
	fill(nx[n + 1], nx[n + 1] + K, n + 1);
	for(int i = n; i; i--){
		for(int j = 0; j < K; j++) nx[i][j] = nx[i + 1][j];
		nx[i][s[i] - 'a'] = i;
	}
	for(int i = 1; i <= q; i++){
		for(int j = 0; j < 3; j++) wh[i][j] = wh[i - 1][j];
		char z; int x;
		scanf(" %c%d", &z, &x);
		x--;
		if(z == '+'){
			char y;
			scanf(" %c", &y);
			t[x][++c[x]] = y;
			p[x][c[x]] = wh[i][x];
			wh[i][x] = c[x];
		}
		else wh[i][x] = p[x][wh[i][x]];
	}
	for(int i = 0; i <= c[0]; i++){
		for(int j = 0; j <= c[1]; j++){
			d[i][j].resize(c[2] + 1);
			for(int k = 0; k <= c[2]; k++){
				if(i || j || k) d[i][j][k] = M;
				else d[i][j][k] = 0;
				if(i && d[p[0][i]][j][k] <= n)
					d[i][j][k] = min(d[i][j][k], nx[d[p[0][i]][j][k] + 1][t[0][i] - 'a']);
				if(j && d[i][p[1][j]][k] <= n)
					d[i][j][k] = min(d[i][j][k], nx[d[i][p[1][j]][k] + 1][t[1][j] - 'a']);
				if(k && d[i][j][p[2][k]] <= n)
					d[i][j][k] = min(d[i][j][k], nx[d[i][j][p[2][k]] + 1][t[2][k] - 'a']);
			}
		}
		for(int j = 1; j <= q; j++) if(wh[j][0] == i)
			ans[j] = (d[wh[j][0]][wh[j][1]][wh[j][2]] <= n);
	}
	for(int i = 1; i <= q; i++) puts(ans[i] ? "YES" : "NO");
}