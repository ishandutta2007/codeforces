#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,x,y,w;
ll res[200500];
bool vis[200500][2][2];

struct SB{
	int x,y,z;ll w;
	bool operator<(const SB a)const{return w>a.w;}
};

vector<pair<int,int> >v[200500];
priority_queue<SB> q;

int main() {
	memset(res,1,sizeof(res));
	res[1]=0;
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	
	q.push({1,0,0,0});
	
	while(!q.empty()){
		auto [x,y,z,w]=q.top();q.pop();
		if(vis[x][y][z])continue;
		vis[x][y][z]=1;
		if(y&&z)res[x]=w;
		for(auto [i,j]:v[x]){
			if(!vis[i][y][z]){
				q.push({i,y,z,w+j});
			}
			if(!y&&!vis[i][1][z]){
				q.push({i,1,z,w+j+j});
			}
			if(!z&&!vis[i][y][1]){
				q.push({i,y,1,w});
			}
			if(!y&&!z&&!vis[i][1][1]){
				q.push({i,1,1,w+j});
			}
		}
	}
	
	for(i=2;i<=n;i++){
		cout<<res[i]<<' ';
	}
}