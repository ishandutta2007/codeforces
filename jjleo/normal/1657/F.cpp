#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

int n, m;
vector<int> c[maxn];
vector<int> v[maxn];

int fa[maxn], dep[maxn];
void dfs(int i){
	dep[i] = dep[fa[i]] + 1;
	for(auto to : v[i]){
		if(to == fa[i]) continue;
		fa[to] = i;
		dfs(to);
	}
}

vector<int> p[maxn];
vector<pair<int, int> > s[maxn];
char S[maxn];

int sk[maxn], top;
bool ins[maxn], vis[maxn];
int x, y;
int dfn[maxn], low[maxn], cnt;
int col[maxn], tot;

void Dfs(int i){
	sk[++top] = i, vis[i] = ins[i] = true;
	dfn[i] = low[i] = ++cnt;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]){
			if(ins[to]) low[i] = min(low[i], low[to]);
		}else{
			Dfs(to);
			low[i] = min(low[i], low[to]);
		}
	} 
	if(dfn[i] == low[i]){
		col[i] = ++tot;
		while(1){
			int x = sk[top--];
			ins[x] = false;
			if(x == i) break;
			col[x] = col[i];
		}
	}
} 

map<int, int> mp[maxn]; 

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i < n;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1);
	for(int i = 1;i <= m;i++){
		int x, y;
		scanf("%d%d%s", &x, &y, S);
		vector<int> a, b;
		while(x ^ y){
			if(dep[x] > dep[y]) a.push_back(x), x = fa[x];
			else b.push_back(y), y = fa[y];
		}
		for(auto x : a) p[i].push_back(x);
		p[i].push_back(x);
		reverse(b.begin(), b.end());
		for(auto x : b) p[i].push_back(x);
		s[i].resize(p[i].size());
		for(int j = 0;j < p[i].size();j++){
			int x = p[i][j];
			s[i][j].first = S[j];
			mp[x][s[i][j].first]++;
		}
		reverse(S, S + p[i].size());
		for(int j = 0;j < p[i].size();j++){
			int x = p[i][j];
			s[i][j].second = S[j];
			if(s[i][j].first ^ s[i][j].second) mp[x][s[i][j].second]++;
		}
	}
	for(int i = 1;i <= n;i++){
		int mx = 0;
		for(auto x : mp[i]) mx = max(mx, x.second);
		for(auto x : mp[i]) if(mx == x.second) c[i].push_back(x.first);
		while(c[i].size() < 2){
			if(c[i].empty()) c[i].push_back('a');
			else if(c[i].back() == 'a') c[i].push_back('b');
			else c[i].push_back('a');
		}
	}
	const int N = n + m;
	for(int i = 1;i <= n;i++) v[i].clear();
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < p[i].size();j++){
			int x = p[i][j];
			int id1 = -1, id2 = -1;
			if(s[i][j].first == c[x][0]) id1 = 0;
			if(s[i][j].first == c[x][1]) id1 = 1;
			if(s[i][j].second == c[x][0]) id2 = 0;
			if(s[i][j].second == c[x][1]) id2 = 1;
			if(id1 == -1 && id2 == -1) return printf("NO"), 0;
			if(id1 != -1) v[n + i].push_back(x + id1 * N);
			else v[n + i].push_back(n + i + N), v[x + (id2 ^ 1) * N].push_back(x + id2 * N);
			if(id2 != -1) v[n + i + N].push_back(x + id2 * N);
			else v[n + i + N].push_back(n + i), v[x + (id1 ^ 1) * N].push_back(x + id1 * N);
			if(id1 == id2){
				v[x + (id1 ^ 1) * N].push_back(x + id1 * N);
			} 
			if(id1 != -1 && id2 != -1 && id1 != id2){
				v[x + id1 * N].push_back(n + i);
				v[x + id2 * N].push_back(n + i + N);
			}
		}
	}
	for(int i = 1;i <= N * 2;i++) if(!vis[i]) Dfs(i); 
	for(int i = 1;i <= N;i++) if(col[i] == col[i + N]) return printf("NO"), 0;
	puts("YES");
	for(int i = 1;i <= n;i++) printf("%c", c[i][col[i] > col[i + N]]);
}