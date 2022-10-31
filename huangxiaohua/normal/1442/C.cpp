#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,n,m,t,k,x,y;
ll f[200500][21],res=1e18,ans[200500],sb=1;
bool vis[200500][21],vis2[200500];
vector<pair<int,int> >v[200500];
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>j>>k;
		v[j].push_back({k,0});
		v[k].push_back({j,1});
	}
	priority_queue<pair<ll,int> >q;
	q.push({0,1*100});
	while(!q.empty()){
		auto [w,x]=q.top();q.pop();
		y=x%100;x/=100;w=-w;
		if(vis[x][y])continue;
		f[x][y]=w;vis[x][y]=1;
		if(x==n)res=min(res,w);
		if(y<=17&&!vis[x][y+1]){
			q.push({-w-(1<<y),x*100+y+1});
		}
		for(auto [i,j]:v[x]){
			if((j&1)!=(y&1))continue;
			if(vis[i][y])continue;
			q.push({-w-1,i*100+y});
		}
	}
	if(res<1e17){
		cout<<res;return 0;
	}
	memset(vis,0,sizeof(vis));
	q.push({0,1*100});
	while(!q.empty()){
		auto [w,x]=q.top();q.pop();
		y=x%100;x/=100;w=-w;
		if(vis[x][y])continue;
		f[x][y]=w;vis[x][y]=1;
		if(x==n)res=min(res,w);
		if(!vis[x][y^1]){
			q.push({-w-1000000,x*100+1-y});
		}
		for(auto [i,j]:v[x]){
			if(j!=y)continue;
			if(vis[i][y])continue;
			q.push({-w-1,i*100+y});
		}
	}
	cout<<(res%1000000+ksm(2,res/1000000)-1)%M;
}