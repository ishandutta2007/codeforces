#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m, dist[3005][3005], dt[3005];
queue<int> q;
vector<int> adj[3005];
vector<pair<int,int> > ord[3005], rev[3005];
tuple<int,int,int,int,int> ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
	}
	for(int i=1;i<=n;i++) {
		dist[i][i] = 1;
		q.push(i);
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			for(auto &nxt : adj[cur]) {
				if(dist[i][nxt]) continue;
				dist[i][nxt] = dist[i][cur] + 1;
				q.push(nxt);
			}
		}
		for(int j=1;j<=n;j++) {
			ord[i].push_back({-dist[i][j], j});
			rev[j].push_back({-dist[i][j], i});
		}
		sort(ord[i].begin(), ord[i].end());
	}
	for(int i=1;i<=n;i++) sort(rev[i].begin(), rev[i].end());
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(dist[i][j] <= 1) continue;
			for(int x=0;x<3;x++) for(int y=0;y<3;y++) {
				if(rev[i][x].X >= -1 || ord[j][y].X >= -1 || rev[i][x].Y == ord[j][y].Y || rev[i][x].Y == j || ord[j][y].Y == i) continue;
				ans = max(ans, make_tuple(dist[i][j]-rev[i][x].X-ord[j][y].X, rev[i][x].Y, i, j, ord[j][y].Y));
			}
		}
	}
	printf("%d %d %d %d\n",get<1>(ans), get<2>(ans), get<3>(ans), get<4>(ans));
}