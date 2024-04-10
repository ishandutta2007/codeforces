#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int n, m;
vector<pair<int, int> > v[maxn];
int x, y;

struct Node{
	int x, y, i, j, k;
	
	bool operator < (const Node &a) const{
		if(y >= 20 || a.y >= 20) return y ^ a.y ? y < a.y : x < a.x;
		return x + (1 << y) < a.x + (1 << a.y);
	}
	
	bool operator > (const Node &a) const{
		if(y >= 20 || a.y >= 20) return y ^ a.y ? y > a.y : x > a.x;
		return x + (1 << y) > a.x + (1 << a.y);
	}
};

Node dis[maxn][25][2];
bool tag[maxn][25][2];
priority_queue<Node, vector<Node>, greater<Node> > q; 


int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back({y, 0}), v[y].push_back({x, 1});
	}
	for(int i = 1;i <= n;i++) for(int j = 0;j <= 20;j++) for(int k = 0;k <= 1;k++) dis[i][j][k] = (Node){(int)1e9, (int)1e9, i, j, k};
	dis[1][0][0] = (Node){0, 0, 1, 0, 0}, q.push(dis[1][0][0]);
	while(!q.empty()){
		int x = q.top().x, y = q.top().y, i = q.top().i, j = q.top().j, k = q.top().k;q.pop();
		if(tag[i][j][k]) continue;
		tag[i][j][k] = true;
		for(int l = 0;l < v[i].size();l++){
			int to = v[i][l].first, co = v[i][l].second;
			Node d;
			if(k ^ co) d = (Node){x + 1, y + 1, to, min(20, j + 1), co};	
			else d = (Node){x + 1, y, to, j, co};	
			int ii = d.i, jj = d.j, kk = d.k;
			if(d < dis[ii][jj][kk]){
				dis[ii][jj][kk] = d;
				q.push(d);
			}
		}
	}
	Node d = (Node){(int)1e9, (int)1e9, 0, 0, 0};
	for(int i = 0;i <= 20;i++) for(int j = 0;j <= 1;j++) d = min(d, dis[n][i][j]);
	int ans = 1;	
	for(int i = 1;i <= d.y;i++) ans = ans * 2 % p;
	ans = (ans + p - 1) % p;
	ans = (ans + d.x) % p;
	printf("%d", ans);
}