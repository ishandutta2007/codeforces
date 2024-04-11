#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+99,sq=500;
 
int n,q,sz[N],ans[N],a[N][2],dp[N][sq];
vector<int> g[N];
 
void dfs1(int x,int par){	
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs1(g[x][i],x);
			f(j,0,sq){
				dp[x][j]+=max(1,dp[g[x][i]][j]-j);
			}
		}
	}	
}
void dfs2(int x,int par){
	sz[x]=1;
	dp[x][0]=-N;
	f(i,1,sq) dp[x][i]=0;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs2(g[x][i],x);
			f_(j,sz[x]/sq+1,0){
				f_(k,sz[g[x][i]]/sq+1,0){
					maxm(dp[x][j+k],dp[x][j]+dp[g[x][i]][k]);
				}
			}
			sz[x]+=sz[g[x][i]];
		}	
	}
	dp[x][0]=1;
	//cout<<x<<" : "<<endl;
	//f(j,0,10){
	//	cout<<j<<" "<<dp[x][j]<<endl;
	//}
}
 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,0);
	cin>>q;
	f(i,0,q){
		cin>>a[i][0]>>a[i][1];
		if(a[i][1]<sq){
			ans[i]=dp[a[i][0]][a[i][1]];
		}
	}
	dfs2(1,0);
	f(i,0,q){
		if(a[i][1]>=sq ){
			int res=0,u=a[i][0],x=a[i][1];
			f(j,1,sq){
				maxm(res,dp[u][j]-(j-1)*x);
			}
			ans[i]=res;
		}
	}
	f(i,0,q){
		cout<<ans[i]<<endl;
	}
}