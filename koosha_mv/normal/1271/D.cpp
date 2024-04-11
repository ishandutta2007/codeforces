#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=5600;
int e,n,m,k,dp[N][N],a[N],b[N],c[N],x,y,sum,par[N],ans=-1;
vector<int> g[N];
int main(){
	cin>>n>>m>>k;
	f(i,0,n+1) par[i]=i;
	f(i,1,n+1)
		cin>>a[i]>>b[i]>>c[i];
	f(i,0,m){
		Gett(x,y);
		maxm(par[y],x);
	}
	f(i,1,n+1)
		g[par[i]].pb(c[i]);
	f(i,0,N) dp[0][i]=-1e9;
	dp[0][k]=0;
	f(i,1,n+1){
		f(j,0,N){
			if(j<b[i]+a[i]) dp[i][j]=-1e9;
			else
				dp[i][j]=dp[i-1][min(j-b[i],(N-1)*1ll)];
		}
		sort(g[i].begin(),g[i].end());
		f(l,0,N){
			sum=0;
			f(j,0,g[i].size()){
				sum+=g[i][g[i].size()-j-1];
				if(l+j+1<N)
					maxm(dp[i][l],dp[i][l+j+1]+sum);
				if(i==n)
					maxm(ans,dp[i][l]);
			}
		}
	}
	cout<<ans<<endl;

}