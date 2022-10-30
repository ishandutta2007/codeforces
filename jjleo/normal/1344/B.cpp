#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int n, m;
char s[maxn][maxn];
bool vis[maxn][maxn];
bool suc = true;
int ans;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool row[maxn], col[maxn];
bool tag1, tag2;


void dfs(int i, int j){
	vis[i][j] = row[i] = col[j] = true;
	for(int k = 0;k < 4;k++){
		int ii = i + dx[k], jj = j + dy[k];
		if(ii && ii <= n && jj && jj <= m && !vis[ii][jj] && s[ii][jj] == '#') dfs(ii, jj); 
	} 
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= n;i++){
		int tag = 0;
		for(int j = 1;j <= m;j++){
			if(tag == 0 && s[i][j] == '#') tag++;
			if(tag == 1 && s[i][j] == '.') tag++;
			if(tag == 2 && s[i][j] == '#') suc = false;
		}
	}
	if(!suc) return printf("-1"), 0; 
	for(int j = 1;j <= m;j++){
		int tag = 0;
		for(int i = 1;i <= n;i++){
			if(tag == 0 && s[i][j] == '#') tag++;
			if(tag == 1 && s[i][j] == '.') tag++;
			if(tag == 2 && s[i][j] == '#') suc = false;
		}
	}
	if(!suc) return printf("-1"), 0; 
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(!vis[i][j] && s[i][j] == '#') dfs(i, j), ans++;
	if(!ans) return printf("0"), 0;
	//for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(!row[i] && !col[j]) row[i] = col[j] = true;
	for(int i = 1;i <= n;i++) if(!row[i]) tag1 = true;
	for(int i = 1;i <= m;i++) if(!col[i]) tag2 = true;
	if(tag1 ^ tag2) return printf("-1"), 0; 
	printf("%d", ans);
}