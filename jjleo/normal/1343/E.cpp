#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n, m, a, b, c;
ll p[maxn];
vector<int> v[maxn];
int x, y;

int dis[3][maxn];
queue<int> q; 
ll ans;

void bfs(int k){
	while(!q.empty()){
		x = q.front();q.pop();
		for(int i = 0;i < v[x].size();i++){
			if(dis[k][v[x][i]] > dis[k][x] + 1) dis[k][v[x][i]] = dis[k][x] + 1, q.push(v[x][i]);
		}
	}
} 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
		for(int i = 1;i <= m;i++) scanf("%lld", &p[i]);
		for(int i = 1;i <= n;i++) v[i].clear(), dis[0][i] = dis[1][i] = dis[2][i] = 0x3f3f3f3f;
		for(int i = 1;i <= m;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x); 
		}	
		sort(p + 1, p + 1 + m);
		for(int i = 1;i <= m;i++) p[i] += p[i - 1];
		dis[0][a] = 0, q.push(a), bfs(0);
		dis[1][b] = 0, q.push(b), bfs(1);
		dis[2][c] = 0, q.push(c), bfs(2);
		ans = 1e18;
		for(int i = 1;i <= n;i++){
			if(dis[0][i] + dis[1][i] + dis[2][i] <= m) ans = min(ans, 2 * p[dis[1][i]] + p[dis[0][i] + dis[1][i] + dis[2][i]] - p[dis[1][i]]);
		}
		printf("%lld\n", ans);
	}
}