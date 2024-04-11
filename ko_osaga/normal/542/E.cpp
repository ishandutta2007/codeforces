#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

vector<int> gph[1005], dfn;
int n, m, bad, col[1005];

void dfs(int x, int c){
	if(col[x]){
		if(col[x] != c) bad = 1;
		return;
	}
	dfn.push_back(x);
	col[x] = c;
	for(auto &i : gph[x]){
		dfs(i, 3-c);
	}
}

int bfs(int x){
	int dis[1005] = {};
	memset(dis, 0x3f, sizeof(dis));
	queue<int> que;
	que.push(x);
	dis[x] = 0;
	while(!que.empty()){
		x = que.front();
		que.pop();
		for(auto &i : gph[x]){
			if(dis[i] > dis[x] + 1){
				dis[i] = dis[x] + 1;
				que.push(i);
			}
		}
	}
	return dis[x];
}

int solve(int x){
	dfn.clear();
	dfs(x, 1);
	if(bad) return -1e9;
	int ret = 0;
	for(auto &i : dfn) ret = max(ret, bfs(i));
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e;
		cin >> s >> e;
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	int ret = 0;
	for(int i=1; i<=n; i++){
		if(!col[i]){
			ret += solve(i);
			if(ret < 0){
				puts("-1");
				return 0;
			}
		}
	}
	cout << ret;
}