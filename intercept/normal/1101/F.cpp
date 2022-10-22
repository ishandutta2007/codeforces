#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=409;
int n,m;
ll a[M],dp[M][M],g[M][M];
struct P{
	int u,v,c;
};
vector<P>p[M];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		int u,v,c,r;
		cin>>u>>v>>c>>r;
		p[r].eb(P{u,v,c});
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=a[j]-a[i];
		}
	}
	ll ans=0;
	for(auto o:p[0]){
		int u=o.u,v=o.v,c=o.c;
		ans=max(ans,dp[u][v]*c);
	}
	for(int t=1;t<=n;++t){
		for(int i=1;i<=n;++i){
			for(int j=i,k=i;j<=n;++j){
				while(dp[i][k]<a[j]-a[k])k++;
				g[i][j]=min(dp[i][k],a[j]-a[k-1]);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j)dp[i][j]=g[i][j];
		}
		for(auto o:p[t]){
			int u=o.u,v=o.v,c=o.c;
			ans=max(ans,dp[u][v]*c);
		}
	}
	cout<<ans<<endl;
	return 0;
}