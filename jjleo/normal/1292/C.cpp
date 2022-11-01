#include <bits/stdc++.h>
#define maxn 3005

using namespace std;

typedef long long ll;

int n;
vector<int> v[maxn];
int x, y;
int siz[maxn][maxn], fa[maxn][maxn];

void dfs1(int i, int rt){
	siz[rt][i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to != fa[rt][i]){
			fa[rt][to] = i;
			dfs1(to, rt);
			siz[rt][i] += siz[rt][to];
		}
	}
}

ll f[maxn][maxn], ans;

ll dfs2(int i, int j){
	if(f[i][j] != -1) return f[i][j];
	if(i == j) return f[i][j] = 0;
	return f[i][j] = max(dfs2(i, fa[i][j]), dfs2(fa[j][i], j)) + siz[i][j] * siz[j][i];
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) dfs1(i, i);
	memset(f, -1, sizeof(f));
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) ans = max(ans, dfs2(i, j));
	printf("%lld", ans);
}