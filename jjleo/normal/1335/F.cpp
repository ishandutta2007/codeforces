#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
int n, m;
#define id(x, y) (x - 1) * m + y

char s[maxn];
bool col[maxn], vis[maxn];
int dir[maxn];
bool cir[maxn], ins[maxn];
int sk[maxn], top;
int to[maxn];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int sum, ans;

void dfs(int i, int j){
	vis[id(i, j)] = ins[id(i, j)] = true, sk[++top] = id(i, j);
	int ii = i + dx[dir[id(i, j)]], jj = j + dy[dir[id(i, j)]];
	if(ins[id(ii, jj)]){
		while(sk[top] != id(ii, jj)) cir[sk[top]] = true, ins[sk[top--]] = false, ++sum;
		cir[sk[top]] = true, ins[sk[top--]] = false, ++sum;
	}
	if(!vis[id(ii, jj)]) dfs(ii, jj);
	if(cir[id(i, j)]){
		ans += col[id(i, j)];
		to[id(ii, jj)] = id(i, j);
	}else{
		if(cir[id(ii, jj)]) to[id(i, j)] = to[id(ii, jj)];
		else to[id(i, j)] = to[to[id(ii, jj)]];
		//printf("%d %d %d %d--\n", i, j, to[id(i, j)] / m + 1, to[id(i, j)] % m);
		if(!col[to[id(i, j)]] && col[id(i, j)]) ans++, col[to[id(i, j)]] = true;
		--top, ins[id(i, j)] = false;
	}
}


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++){
			scanf("%s", s + 1);
			for(int j = 1;j <= m;j++){
				col[id(i, j)] = (s[j] - '0') ^ 1;
			}
		}
		for(int i = 1;i <= n;i++){
			scanf("%s", s + 1);
			for(int j = 1;j <= m;j++){
				switch(s[j]){
					case 'U':
						dir[id(i, j)] = 0;
						break;
					case 'R':
						dir[id(i, j)] = 1;
						break;
					case 'D':
						dir[id(i, j)] = 2;
						break;
					case 'L':
						dir[id(i, j)] = 3;
						break;			
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				vis[id(i, j)] = cir[id(i, j)] = ins[id(i, j)] = false;
			}
		}
		sum = ans = top = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(!vis[id(i, j)]) dfs(i, j); 
			}
		}
		printf("%d %d\n", sum, ans);
	}
}