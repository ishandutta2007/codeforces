#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

int n, q, k;
int x, y;
vector<int> v1[maxn], v2[maxn];
int p[maxn];
bool vis[maxn];
int ans;

int dfn[maxn], cnt;
int dep[maxn], fa[maxn][25], sum[maxn];
int lg[maxn];

void dfs1(int i){
	dfn[i] = ++cnt, dep[i] = dep[fa[i][0]] + 1;
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j];
		if(to == fa[i][0]) continue;
		fa[to][0] = i, dfs1(to);
	}
}

inline int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

inline bool cmp(int x, int y){
	return dfn[x] < dfn[y];
}

int sk[maxn], top;

void insert(int x){
	if(!top){
		sk[++top] = x;
		return;
	}
	int y = sk[top], z = lca(x, y);
	if(z == y){//  
		sk[++top] = x;
		return;
	}
	//
	while(dfn[sk[top]] > dfn[z]){// LCALCA 
		y = sk[top--];
		if(!top || dfn[sk[top]] <= dfn[z]) break;
		v2[sk[top]].push_back(y);
		
	}
	if(!top || sk[top] != z){//lca 
		sk[++top] = z;// 
	}
	v2[z].push_back(y);
	sk[++top] = x;
}

int dfs2(int i){
	int sum = 0;
	for(int j = 0;j < v2[i].size();j++){
		sum += dfs2(v2[i][j]);
	}
	v2[i].clear();
	if(vis[i]){
		ans += sum, vis[i] = false;
		return 1;
	}else{
		if(sum > 1){
			++ans;
			return 0;
		}else{
			return sum;
		}
	}
	
}

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v1[x].push_back(y), v1[y].push_back(x);
	}
	dfs1(1);
	scanf("%d", &q);
	while(q--){
		scanf("%d", &k);
		for(int i = 1;i <= k;i++) scanf("%d", &p[i]), vis[p[i]] = true;
		sort(p + 1, p + 1 + k, cmp);
		p[k + 1] = p[1];
		bool tag = false;
		for(int i = 1;i <= k;i++){
			if(vis[fa[p[i]][0]]){
				tag = true, puts("-1");
				for(int j = 1;j <= k;j++) vis[p[j]] = false;//debug:  
				break;
			}
		}
		if(tag) continue;
		//for(int i = 1;i <= k;i++) vis[p[i]] = true;//debug:-1 gg  
		sk[++top] = 1;
		for(int i = 1;i <= k;i++) if(p[i] ^ 1) insert(p[i]);
		while(top){// 
			if(--top) v2[sk[top]].push_back(sk[top + 1]);
		}
		ans = 0, dfs2(1);
		printf("%d\n", ans);
	}
}