#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m, k;
vector<int> v[maxn];
int x, y;
bool vis[maxn];
int dep[maxn];
int sk[maxn], top;
bool tag[maxn];
int cnt;
int ans[maxn];

void dfs1(int i, int fa){
	
	vis[i] = true, dep[i] = dep[fa] + 1, sk[++top] = i;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		if(!vis[to]) dfs1(to, i);
		else if(dep[i] > dep[to] && dep[i] - dep[to] + 1 <= k){
			printf("2\n%d\n", dep[i] - dep[to] + 1);
			while(1){
				printf("%d ", sk[top]);
				if(sk[top--] == to) break;
			}
			exit(0);
		}
	}
	--top;
}

void dfs2(int i, int fa){
	vis[i] = true;
	bool suc = !tag[fa];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]){
			if(tag[to]){
				suc = false;
				break;
			}
		}
	}
	if(suc){
		tag[i] = true;
		ans[++cnt] = i;
		if(cnt == (k + 1) / 2){
			for(int j = 1;j <= cnt;j++) printf("%d ", ans[j]);
			exit(0);
		}
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(!vis[to]) dfs2(to, i);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs1(1, 0);
	memset(vis, 0, sizeof(vis));
	puts("1");
	dfs2(1, 0);
	memset(vis, 0, sizeof(vis)), memset(tag, 0, sizeof(tag)), cnt = 0, tag[0] = true;
	dfs2(1, 0); 
}