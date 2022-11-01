#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, m;
ll d[maxn][2][2];
bool vis[maxn][2][2];
vector<pair<int, int> > v[maxn];
int x, y, z;

struct Node{
	ll d;
	int i, j, k;
};

inline bool operator < (Node a, Node b){
	return a.d > b.d;
}

priority_queue<Node> q;

int main(){
	scanf("%d%d", &n, &m);
	memset(d, 0x3f, sizeof(d));
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({y, z}), v[y].push_back({x, z});
	}
	d[1][0][0] = 0;
	q.push({d[1][0][0], 1, 0, 0});
	while(!q.empty()){
		int i = q.top().i, j = q.top().j, k = q.top().k;q.pop();
		if(vis[i][j][k]) continue;
		vis[i][j][k] = true;
		for(int l = 0;l < v[i].size();l++){
			int to = v[i][l].first, co = v[i][l].second;
			if(d[to][j][k] > d[i][j][k] + co){
				d[to][j][k] = d[i][j][k] + co;
				q.push({d[to][j][k], to, j, k});
			}
			if(j == 0 && d[to][1][k] > d[i][j][k] + 2 * co){
				d[to][1][k] = d[i][j][k] + 2 * co;
				q.push({d[to][1][k], to, 1, k});
			}
			if(k == 0 && d[to][j][1] > d[i][j][k]){
				d[to][j][1] = d[i][j][k];
				q.push({d[to][j][1], to, j, 1});
			}
			if(j == 0 && k == 0 && d[to][1][1] > d[i][j][k] + co){
				d[to][1][1] = d[i][j][k] + co;
				q.push({d[to][1][1], to, 1, 1});
			}
		}
	}
	for(int i = 2;i <= n;i++) printf("%lld ", d[i][1][1]); 
}//