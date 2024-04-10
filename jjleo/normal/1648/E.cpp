#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int t, n, m;
pair<int, int> E[maxn];
pair<int, int> e[maxn];
set<pair<int, int> > st;

int fa[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

vector<int> v[maxn];
set<int> w[maxn];
int val[maxn], son[maxn][2];

bool check(int i, int j){
	for(auto x : v[i]){
		for(auto y : v[j]){
			if(st.find({min(x, y), max(x, y)}) == st.end()) return true;
		}
	}
	return false;
} 

int f[maxn][25], dep[maxn];
int lg[maxn];

void dfs(int i){
	dep[i] = dep[f[i][0]] + 1;
	for(int j = 1;j <= 20;j++) f[i][j] = f[f[i][j - 1]][j - 1];
	if(son[i][0]) for(int j = 0;j <= 1;j++) f[son[i][j]][0] = i, dfs(son[i][j]);
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = f[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0]; 
}

int main(){
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		st.clear();
		for(int i = 1;i <= m;i++){
			scanf("%d%d", &E[i].first, &E[i].second);
			scanf("%d", &e[i].first), e[i].second = i;
			st.insert({min(E[i].first, E[i].second), max(E[i].first, E[i].second)});
		}
		sort(e + 1, e + 1 + m);
		for(int i = 1;i <= n;i++) fa[i] = i, v[i].clear(), v[i].push_back(i);
		for(int i = 1;i < n * 2;i++) w[i].clear(), w[i].insert(i);
		int cnt = n;
		for(int i = 1;i <= m;i++){
			int x = find(E[e[i].second].first), y = find(E[e[i].second].second), z = e[i].first;
			if(x == y) continue;
			if(v[x].size() > v[y].size()) swap(x, y);
			vector<int> B;
			for(auto i : w[x]){
				vector<int> b;
				for(auto j : w[y]){
					if(check(i, j)) b.push_back(j);
				}
				int now = i;
				for(auto j : b){
					w[y].erase(j);
					son[++cnt][0] = now, son[cnt][1] = j;
					val[cnt] = z;
					swap(v[cnt], v[now]), now = cnt;
					if(v[j].size() > v[now].size()) swap(v[now], v[j]);
					v[now].insert(v[now].end(), v[j].begin(), v[j].end());
				}
				if(now == i) B.push_back(i);
				else w[y].insert(now); 
			}
			w[x].clear();
			for(auto i : B) w[x].insert(i);
			for(auto i : w[y]) w[x].insert(i);
			fa[y] = x;
		}
		for(int i = 0;i <= 20;i++) f[cnt][i] = 0;
		dfs(cnt);
		for(int i = 1;i <= m;i++) printf("%d ", val[lca(E[i].first, E[i].second)]);puts("");
	}
}