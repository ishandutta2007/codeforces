#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

char s[3][maxn];
int nxt[3][maxn];
int len[3];

inline void kmp(int k){
	for(int i = 1;i < len[k];i++){
		int j = nxt[k][i - 1];
		while(j && s[k][i] != s[k][j]) j = nxt[k][j - 1];
		if(s[k][i] == s[k][j]) j++;
		nxt[k][i] = j;
	}
} 

bool vis[3];
int ans = maxn * 3;


void dfs(int d, int x, int val){
	//printf("%d %d %d--\n", d, x, val);
	if(d == 3){
		ans = min(ans, val);
		return;
	}
	for(int y = 0;y < 3;y++){
		if(!vis[y]){
			vis[y] = true;
			bool tag = false;
			int j = 0;
			for(int i = 0;i < len[x];i++){
				while(j && s[y][j] != s[x][i]) j = nxt[y][j - 1];
				if(s[y][j] == s[x][i]) j++;
				if(j == len[y]) tag = true;
			}
			if(tag) dfs(d + 1, x, val);
			dfs(d + 1, y, val + len[y] - j);
			vis[y] = false;
		}
	}
}

int main(){
	for(int i = 0;i < 3;i++) scanf("%s", s[i]), len[i] = strlen(s[i]), kmp(i);
	for(int i = 0;i < 3;i++) vis[i] = true, dfs(1, i, len[i]), vis[i] = false;
	printf("%d", ans);
}