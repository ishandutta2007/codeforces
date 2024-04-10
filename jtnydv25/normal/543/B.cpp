#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define sd(x) scanf("%d", &(x))

const int N = 3005;
vi con[N];
int dist[N][N];
int vis[N];
const int INF = 1e9;
void bfs(int s){
	for(int i = 0; i < N; i++) dist[s][i] = INF;
	dist[s][s] = 0;

	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : con[u]){
			if(dist[s][v] == INF){
				dist[s][v] = dist[s][u] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	int n, m, s1, t1, s2, t2, a, b, l1, l2;
	sd(n); sd(m);
	for(int i = 1; i <= m; i++){
		sd(a); sd(b);
		con[a].pb(b);
		con[b].pb(a);
	}

	sd(s1); sd(t1); sd(l1);
	sd(s2); sd(t2); sd(l2);

	for(int i = 1; i <= n; i++) bfs(i);
	if(l1 < dist[s1][t1] || l2 < dist[s2][t2]){
		printf("-1");
		return 0;
	}

	int ans = max(-1, m - (dist[s1][t1] + dist[s2][t2]));
	for(int s = 1; s <= n; s++){
		for(int t = 1; t <= n; t++){
			int l = dist[s][t];
			assert(dist[s][t] != INF);
			if(dist[s1][s] + dist[t1][t] + l <= l1 && dist[s2][s] + dist[t2][t] + l <= l2){
				int D = dist[s1][s] + dist[t1][t] + l + dist[s2][s] + dist[t2][t];
				ans = max(ans, m - D);
			}

			if(dist[s1][s] + dist[t1][t] + l <= l1 && dist[t2][s] + dist[s2][t] + l <= l2){
				int D = dist[s1][s] + dist[t1][t] + l + dist[t2][s] + dist[s2][t];
				ans = max(ans, m - D);
			}

			// if(dist[t1][s] + dist[s1][t] + l <= l1 && dist[s2][s] + dist[t2][t] + l <= l2){
			// 	int D = dist[t1][s] + dist[s1][t] + l + dist[s2][s] + dist[t2][t];
			// 	ans = max(ans, m - D);
			// }

			// if(dist[t1][s] + dist[s1][t] + l <= l1 && dist[t2][s] + dist[s2][t] + l <= l2){
			// 	int D = dist[t1][s] + dist[s1][t] + l + dist[t2][s] + dist[s2][t];
			// 	ans = max(ans, m - D);
			// }
		}
	}
	printf("%d", ans);
}