#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const ll mod=998244353;
const int N=200100,M=20,K=2;
vector<int>g[N][K];
int n,m;

ll powmod(ll a,ll b){
	if(!b)return 1;
	if(b%2)return powmod(a*a%mod,b/2)*a%mod;
	return powmod(a*a%mod,b/2);
}
 
struct dj{int tr=0,mv=0,node=0,gt=0;};
bool operator<(const dj &a, const dj &b){
	if(a.tr<=M&&b.tr<=M)return (1<<a.tr)+a.mv<(1<<b.tr)+b.mv;
	if(a.tr==b.tr)return a.mv<b.mv;
	return a.tr<b.tr;
}
bool operator>(const dj &a, const dj &b){return b < a;}
dj dp[N][K][M];
bool vis[N][K][M];
 
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u][0].push_back(v);
		g[v][1].push_back(u);
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<K;++j)
			for(int k=0;k<M;++k)
				dp[i][j][k]={(int)1e9,(int)1e9,i,j};
	priority_queue<dj,vector<dj>,greater<dj>>q;q.push(dp[0][0][0]={0,0,0,0});
	while(q.size()){
		auto d=q.top();q.pop();
		if(d.node==n-1){cout<<(powmod(2,d.tr)-1+d.mv+mod)%mod<<endl;return 0;}
		if(vis[d.node][d.gt][min(19,d.tr)])continue;
		vis[d.node][d.gt][min(19,d.tr)]=true;
		for(int i=0;i<K;++i)
			for(auto v:g[d.node][i])
				if(dp[v][i][min(19,d.tr+(d.gt!=i))]>(dj){d.tr+(d.gt!=i),d.mv+1,v,i})
					q.push(dp[v][i][min(19,d.tr+(d.gt!=i))]={d.tr+(d.gt!=i),d.mv+1,v,i});
	}
}