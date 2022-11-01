#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int n, m, k;
int a[maxn][maxn];
vector<pair<int, int> > v[maxn];
int t;
int x, y, xx, yy;
int dis[maxn][maxn][50];
queue<pair<int, int> > q;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool vis[50];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[i][j]), v[a[i][j]].push_back({i, j});
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1;i <= k;i++){
		memset(vis, 0, sizeof(vis)), vis[i] = true;
		for(int j = 0;j < v[i].size();j++) dis[v[i][j].first][v[i][j].second][i] = 0, q.push(v[i][j]);
		while(!q.empty()){
			pair<int, int> p = q.front();q.pop();
			for(int j = 0;j < 4;j++){
				int ii = p.first + dx[j], jj = p.second + dy[j];
				if(ii && ii <= n && jj && jj <= m && dis[ii][jj][i] > dis[p.first][p.second][i] + 1){
					dis[ii][jj][i] = dis[p.first][p.second][i] + 1;
					q.push({ii, jj});
				}
			}
			int c = a[p.first][p.second];
			if(!vis[c]){
				vis[c] = true;
				for(int j = 0;j < v[c].size();j++){
					if(dis[v[c][j].first][v[c][j].second][i] > dis[p.first][p.second][i] + 1){
						dis[v[c][j].first][v[c][j].second][i] = dis[p.first][p.second][i] + 1;
						q.push({v[c][j].first, v[c][j].second});
					}
				}
			}
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		int ans = abs(x - xx) + abs(y - yy);
		for(int i = 1;i <= k;i++) ans = min(ans, dis[x][y][i] + dis[xx][yy][i] + 1);
		printf("%d\n", ans);
	}
}