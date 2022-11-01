#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, m;
vector<pair<int, int> > v[maxn];
int x, y, z;
ll d[maxn][55];
bool vis[maxn][55];

struct Node{
    ll val, x, y;
 
    bool operator < (const Node& a) const{
        return val > a.val;
    }
};

priority_queue<Node> q;

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({y, z}), v[y].push_back({x, z});
	}
	memset(d, 0x3f, sizeof(d));
	d[1][0] = 0, q.push({0, 1, 0});
	while(!q.empty()){
		int x = q.top().x, y = q.top().y;q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = true;
		for(int i = 0;i < v[x].size();i++){
			int to = v[x][i].first, co = v[x][i].second;
			if(y){
				if(d[to][0] > d[x][y] + (co + y) * (co + y)){
					d[to][0] = d[x][y] + (co + y) * (co + y);
					q.push((Node){d[to][0], to, 0});
				}
			}else{
				if(d[to][co] > d[x][y]){
					d[to][co] = d[x][y];
					q.push((Node){d[to][co], to, co});
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) printf("%lld ", d[i][0] >= 1e18 ? -1 : d[i][0]);
}