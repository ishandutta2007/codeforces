#include <bits/stdc++.h>
using namespace std;
const int N = 410;
bool vis[N], con[N][N];
int dist[N];
int bfs(bool road, int n){
	int s = 1;
	dist[1] = 0;
	queue<int > q;
	q.push(s);vis[s] = 1;
	while(!q.empty()){
		int P = q.front();
		q.pop();
		for(int i = 1; i <= n; i++){
			if(i != P && (road ^ con[P][i]) && !vis[i]){
				vis[i] = 1;
				q.push(i);
				dist[i] = dist[P] + 1;
			}
		}
	}
	return (dist[n] == 0 ? -1 : dist[n]);
}	
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		con[u][v] = con[v][u] = 1;
	}
	int ans = (con[1][n] ? bfs(1, n) : bfs(0, n));
	printf("%d\n", ans);
}