#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int t, n;
char s[maxn][maxn][maxn];
bool vis[maxn];
vector<int> v[maxn];

inline bool check(int i, int j, int k){
	if(i > j) swap(i, j);
	return s[i][j - i][k] == '1';
}

void dfs(int i, int fa){
	vis[i] = true;
	for(int j = 1;j <= n;j++){
		if(vis[j] || j == fa) continue;
		if(check(j, fa, i)) v[i].push_back(j), v[j].push_back(i), dfs(j, i);
	}
}

int d[maxn][maxn];

void dfs(int i, int fa, int x){
	if(fa) d[x][i] = d[x][fa] + 1;
	for(auto to : v[i]){
		if(to == fa) continue;
		dfs(to, i, x);
	}
}

bool check(){
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				if((d[i][k] == d[j][k]) != check(i, j, k)) return false;
			}
		}
	}
	return true;
}

void solve(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		for(int j = 1;j <= n - i;j++){
			scanf("%s", s[i][j] + 1);
		}
	}
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= n;j++) v[j].clear(), vis[j] = false;
		vis[1] = vis[i] = true;
		dfs(1, i), dfs(i, 1);
		v[1].push_back(i), v[i].push_back(1);
		bool tag = false;
		for(int j = 1;j <= n;j++) if(!vis[j]) tag = true;
		if(tag) continue;
		for(int j = 1;j <= n;j++) dfs(j, 0, j);
		if(check()){
			puts("Yes");
			for(int j = 1;j <= n;j++) for(auto to : v[j]) if(j < to) printf("%d %d\n", j, to);
			return;
		}
	}
	puts("No");
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}