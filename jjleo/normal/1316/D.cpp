#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
#define id(x, y) ((x - 1) * n + y)

int to[maxn];
char s[maxn];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char ds[4] = {'L', 'R', 'U', 'D'};

void dfs(int i, int j){
	for(int k = 0;k < 4;k++){
		int ii = i + dx[k], jj = j + dy[k];
		if(ii && ii <= n && jj && jj <= n && to[id(i, j)] == to[id(ii, jj)] && !s[id(ii, jj)]){
			s[id(ii, jj)] = ds[k];
			dfs(ii, jj);
		}
	}
}

int x, y;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d%d", &x, &y);
			to[id(i, j)] = x == -1 ? -1 : id(x, y);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(to[id(i, j)] == id(i, j)) s[id(i, j)] = 'X', dfs(i, j);
			if(to[id(i, j)] == -1){
				for(int k = 0;k < 4;k++){
					int ii = i + dx[k], jj = j + dy[k];
					if(ii && ii <= n && jj && jj <= n && to[id(i, j)] == to[id(ii, jj)] && !s[id(ii, jj)]){
						s[id(ii, jj)] = ds[k], dfs(ii, jj);
						break;
					}
				}
			}
		}
	}
	for(int i = 1;i <= n * n;i++) if(!s[i]) return printf("INVALID"), 0;
	printf("VALID\n");
	for(int i = 1;i <= n * n;i++){
		printf("%c", s[i]);
		if(i % n == 0) puts("");
	}
}