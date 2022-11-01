#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n, m;
vector<int> v[maxn];
map<int, int> mp, f[maxn][2];
int x;
int cnt, tot;
vector<pair<int, int> > e[maxn];
bool vis[maxn];
int cur[maxn];
vector<int> ans;
int a[maxn];

void dfs(int i){
	for(int &j = cur[i];j < e[i].size();j++){
		int to = e[i][j].first, id = e[i][j].second;
		if(vis[id]) continue;
		vis[id] = true;
		dfs(to);
	}
	ans.push_back(i);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &m);
		while(m--){
			scanf("%d", &x);
			v[i].push_back(x);
			mp[x]++;
		}
	} 
	for(auto x : mp) if(x.second & 1) return printf("NO"), 0;
	cnt = n;
	for(auto &x : mp) a[x.second = ++cnt] = x.first;
	for(int i = 1;i <= n;i++) for(int j = 0;j < v[i].size();j++){
		int to = mp[v[i][j]];
		e[i].push_back({to, ++tot}), e[to].push_back({i, tot});
	}
	for(int i = 1;i <= n;i++){
		ans.clear();
		dfs(i);
		int last = 0;
		for(int i = ans.size() - 1;~i;i--){
			x = ans[i];
			if(last){
				if(last <= n) f[last][0][a[x]]++;
				else f[x][1][a[last]]++;
			}
			last = x;
		}
	}
	puts("YES");
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < v[i].size();j++){
			x = v[i][j];
			if(f[i][0][x]) printf("L"), f[i][0][x]--;
			else printf("R"), f[i][1][x]--;
		}
		puts("");
	}
}