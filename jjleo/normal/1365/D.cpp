#include <bits/stdc++.h>
#define maxn 100086 
using namespace std;

int T; 
int n, m;
char S[100][100];

bool vis[100][100];
int sum;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void Dfs(int x, int y){
	if(S[x][y] == 'G') sum--;
	vis[x][y] = true;
	for(int i = 0;i < 4;i++){
		int xx = x + dx[i], yy = y + dy[i];
		if(xx && xx <= n && yy && yy <= m && !vis[xx][yy] && S[xx][yy] != '#'){
			Dfs(xx, yy);
		}
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", S[i] + 1);
		bool tag = false;
		sum = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(S[i][j] == 'G'){
					sum++;
				}else if(S[i][j] == 'B'){
					for(int k = 0;k < 4;k++){
						int ii = i + dx[k], jj = j + dy[k];
						if(ii && ii <= n && jj && jj <= m){
							if(S[ii][jj] == 'G') tag = true;
							if(S[ii][jj] == '.') S[ii][jj] = '#';
						}
					}
				}
			}
		}
		if(tag){
			puts("No");
			continue;
		}
		if(S[n][m] != '#') Dfs(n, m);
		puts(!sum ? "Yes" : "No");
	} 
}