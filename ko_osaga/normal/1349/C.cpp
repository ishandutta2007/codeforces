#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1005;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
char str[MAXN][MAXN];
lint dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pi> dfn;

bool ok(int x, int y){
	return 0<=x&&x<n&&0<=y&&y<m;
}

void dfs(int x, int y){
	if(vis[x][y]) return;
	vis[x][y] = 1;
	dfn.emplace_back(x, y);
	for(int i=0; i<4; i++){
		if(ok(x + dx[i], y + dy[i]) && str[x][y] == str[x + dx[i]][y + dy[i]]){
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

queue<pi> que;

void enque(int x, int y, int d){
	if(!ok(x, y)) return;
	if(dist[x][y] > d){
		dist[x][y] = d;
		que.emplace(x, y);
		return;
	}
}

int main(){
	int q;
	memset(dist, 0x3f, sizeof(dist));
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0; i<n; i++) scanf("%s",str[i]);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(vis[i][j]) continue;
			dfn.clear();
			dfs(i, j);
			if(sz(dfn) == 1){
				continue;
			}
			for(auto &[x, y] : dfn){
				enque(x, y, 0);
			}
		}
	}
	while(sz(que)){
		pi v = que.front(); que.pop();
		for(int i=0; i<4; i++) enque(v.first + dx[i], v.second + dy[i], dist[v.first][v.second] + 1);
	}
	while(q--){
		int x, y; lint v;
		scanf("%d %d %lld",&x,&y,&v);
		x--; y--;
		if(dist[x][y] > v) printf("%c\n", str[x][y]);
		else{
			lint delta = v - dist[x][y];
			if(delta & 1) str[x][y] ^= 1;
			printf("%c\n", str[x][y]);
			if(delta & 1) str[x][y] ^= 1;
		}
	}
}