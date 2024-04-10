#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n, x;
int p[maxn];
vector<int> v[maxn];
bool vis[maxn], tag[maxn];

void dfs(int i, int x){
	if(x) tag[i] = true;
	vis[i] = true;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]) continue;
		dfs(to, x ^ 1);
		break;
	}
}

int main(){
	scanf("%d", &n);
	if(n & 1){
		puts("Second"), fflush(stdout);
		for(int i = 1;i <= n * 2;i++){
			scanf("%d", &x);
			if(p[x]) v[i].push_back(p[x]), v[p[x]].push_back(i);
			else p[x] = i;
		}
		for(int i = 1;i <= n;i++) v[i].push_back(i + n), v[i + n].push_back(i);
		for(int i = 1;i <= n * 2;i++) if(!vis[i]) dfs(i, 0);
		x = 0;
		for(int i = 1;i <= n * 2;i++){
			if(!tag[i]) continue;
			x += i;
			if(x >= 2 * n) x -= 2 * n;
		}
		if(x) for(int i = 1;i <= n * 2;i++) tag[i] ^= 1;
		for(int i = 1;i <= n * 2;i++) if(tag[i]) printf("%d ", i);
		puts("");
	}else{
		puts("First"), fflush(stdout);
		for(int i = 1;i <= n;i++) printf("%d ", i);
		for(int i = 1;i <= n;i++) printf("%d ", i);
		puts("");
	}
}