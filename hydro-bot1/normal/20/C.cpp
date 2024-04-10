// Hydro submission #6220517d3d794d828a9c8167@1646285182061
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int head[200100], to[200100], nex[200100], val[200100], tot = 0;
int n, m;
ll pre[200100], vis[200100], dist[200100];
priority_queue<pair<ll, ll>> que;
void add(int x, int y, int z){
	to[++tot] = y;
	nex[tot] = head[x];
	val[tot] = z;
	head[x] = tot;
}

void dijkstra(int s){
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	que.push({0, s});
	dist[s] = 0;
	while(!que.empty()){
		int x = que.top().second; que.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = nex[i]){
			int y = to[i];
			if(dist[y] > dist[x] + val[i]){
				pre[y] = x;
				dist[y] = dist[x] + val[i];
				que.push({-dist[y], y});
			}
		}
	}
}


void slove(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v, z; cin >> u >> v >> z;
		add(u, v, z);
		add(v, u, z);
	}
	dijkstra(1);
	if(pre[n]) {
		vector<ll> ans;
		int p = n;
		while(p != 0){
			ans.push_back(p);
			p = pre[p];
		}
		reverse(ans.begin(), ans.end());
		for(auto c : ans){
			cout << c << ' ';
		}
	} else{
		cout << -1 << '\n';
	}
}

int main(){
	slove();


}