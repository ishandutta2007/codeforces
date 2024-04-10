#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,vis[200500];
ll w,f[200500];

vector<pair<int,ll> >v[200500];
priority_queue<pair<ll,int> >q;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%lld",&x,&y,&w);
		v[x].push_back({y,w*2});
		v[y].push_back({x,w*2});
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&w);
		v[0].push_back({i,w});
	}
	q.push({0,0});
	while(!q.empty()){
		auto [y,x]=q.top();q.pop();y=-y;
		if(vis[x]){continue;}vis[x]=1;f[x]=y;
		for(auto [i,j]:v[x]){
			if(vis[i]){continue;}
			q.push({-j-y,i});
		}
	}
	for(i=1;i<=n;i++){
		printf("%lld ",f[i]);
	}
}