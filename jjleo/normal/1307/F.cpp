#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int n, k, r;
int x, y;
vector<int> v[maxn];
int cnt;
queue<int> q;
int dis[maxn];

int fa[maxn];
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

inline void unionSet(int x, int y){
	x = find(x), y = find(y);
	if(x ^ y) fa[x] = y;
}

int f[maxn][25], dep[maxn], lg[maxn];

void dfs(int i){
	for(int j = 1;j <= 20;j++) f[i][j] = f[f[i][j - 1]][j - 1];
	dep[i] = dep[f[i][0]] + 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == f[i][0]) continue;
		f[to][0] = i, dfs(to);
	}
}


inline int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = f[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

inline int get(int x, int y){
	int i = 0;
	while(y){
		if(y & 1) x = f[x][i];
		y >>= 1, i++;
	}
	return x;
}


int main(){
	scanf("%d%d%d", &n, &k, &r), cnt = n;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(++cnt), v[cnt].push_back(x);
		v[y].push_back(cnt), v[cnt].push_back(y);//debug:++  
	}
	n = cnt;
	for(int i = 1;i <= n;i++) fa[i] = i;
	memset(dis, -1, sizeof(dis)); 
	while(r--){
		scanf("%d", &x);
		q.push(x), dis[x] = 0;
	}
	while(!q.empty()){
		x = q.front();q.pop();
		if(dis[x] == k) continue;
		for(int i = 0;i < v[x].size();i++){
			y = v[x][i];
			unionSet(x, y);
			if(dis[y] == -1) dis[y] = dis[x] + 1, q.push(y);//debug:dis[y]y 
		}
	}
	for(int i = 2;i <= n;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	dfs(1);
	scanf("%d", &r);
	while(r--){
		scanf("%d%d", &x, &y);
		int z = lca(x, y), len = dep[x] + dep[y] - 2 * dep[z];
		//printf("%d %d %d--\n", x, y, z);
		if(len <= 2 * k){
			puts("YES");
			continue;
		}
		if(dep[x] - dep[z] < k){
			x = get(y, len - k);
			y = get(y, k);
		}else if(dep[y] - dep[z] < k){
			y = get(x, len - k);
			x = get(x, k);
		}else{
			x = get(x, k);
			y = get(y, k);
		}
		puts(find(x) == find(y) ? "YES" : "NO"); 
	}
}