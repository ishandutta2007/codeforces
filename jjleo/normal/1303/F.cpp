#include <bits/stdc++.h>
#define maxn 305
#define maxm 3000086

using namespace std;

int n, m, q;

int fa[maxm], siz[maxm];

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int x[maxm], y[maxm], z[maxm];
int c[maxn][maxn];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}; 
int sum[maxm];
int id[maxn][maxn], cnt;

inline void unionSet(int x, int y){
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x];
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	sum[0] = 1;
	for(int i = 1;i < maxm;i++) fa[i] = i, siz[i] = 1;
	for(int i = 1;i <= q;i++){
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
		if(c[x[i]][y[i]] == z[i]) continue;
		++sum[i];
		swap(c[x[i]][y[i]], z[i]);
		id[x[i]][y[i]] = ++cnt;
		for(int j = 0;j < 4;j++){
			int ii = x[i] + dx[j], jj = y[i] + dy[j];
			if(ii && ii <= n && jj && jj <= m && c[x[i]][y[i]] == c[ii][jj]){
				int X = find(id[x[i]][y[i]]), Y = find(id[ii][jj]);
				if(X ^ Y) sum[i]--, unionSet(X, Y);
			}
		}
		//printf("%d %d--\n", i, sum[i]); 
	}
	for(int i = 1;i < maxm;i++) fa[i] = i, siz[i] = 1;
	cnt = 0;memset(id, 0, sizeof(id));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(!id[i][j]) id[i][j] = ++cnt;
			for(int k = 0;k < 4;k++){
				int ii = i + dx[k], jj = j + dy[k];
				if(ii && ii <= n && jj && jj <= m && c[i][j] == c[ii][jj]){
					if(!id[ii][jj]) id[ii][jj] = ++cnt;
					int X = find(id[i][j]), Y = find(id[ii][jj]);
					if(X ^ Y) unionSet(X, Y);
				}
			}
		}
	}
	for(int i = q;i;i--){
		if(c[x[i]][y[i]] == z[i]) continue;
		swap(c[x[i]][y[i]], z[i]);
		--sum[i];
		id[x[i]][y[i]] = ++cnt;
		for(int j = 0;j < 4;j++){
			int ii = x[i] + dx[j], jj = y[i] + dy[j];
			if(ii && ii <= n && jj && jj <= m && c[x[i]][y[i]] == c[ii][jj]){
				int X = find(id[x[i]][y[i]]), Y = find(id[ii][jj]);
				if(X ^ Y) sum[i]++, unionSet(X, Y);
			}
		}
		//printf("%d %d--\n", i, sum[i]); 
	}
	for(int i = 1;i <= q;i++) printf("%d\n", sum[i] += sum[i - 1]);
}