#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int t, n, m;
char a[maxn][maxn];
bool vis[maxn][maxn];
int cnt, l, r, d, u;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void dfs(int i, int j){
	if(vis[i][j] || a[i][j] == '0') return;
	vis[i][j] = true, cnt++;
	l = min(l, i), r = max(r, i), d = min(d, j), u = max(u, j);
	for(int k = 0;k < 4;k++){
		int ii = i + dx[k], jj = j + dy[k];
		if(ii && ii <= n && jj && jj <= m) dfs(ii, jj);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", a[i] + 1);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) vis[i][j] = false;
		bool tag = false;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(!vis[i][j] && a[i][j] == '1'){
			l = 1e9, r = 0, d = 1e9, u = 0, cnt = 0;
			dfs(i, j);
			if((r - l + 1) * (u - d + 1) != cnt) tag = true;
		}
		puts(tag ? "NO" : "YES");
	}
}