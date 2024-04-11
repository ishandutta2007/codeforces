#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3005;

int n,m,x,y,t,b[N],w[N],sub[N];
vector<int> g[N];
pair<ll,ll> dp[N][N],e;

pair<ll,ll> max_m(pair<ll,ll> p1,pair<ll,ll> p2,pair<ll,ll> p3){
	p2.F+=p3.F,p2.S+=p3.S;
	if(p1.F>p2.F || (p1.F==p2.F && p1.S>p2.S))
		return p1;
	return p2;
}
void dfs(int x,int par){
	f(i,1,m+1) dp[x][i].S=dp[x][i].F=-1e18;
	
	sub[x]=1;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			sub[x]+=sub[g[x][i]];
			f_(j,min(sub[x],m),0){
				dp[x][j].F+=dp[g[x][i]][0].F,dp[x][j].S+=dp[g[x][i]][0].S;
				for(int k=min(sub[x]-sub[g[x][i]],j-1);k>=j-sub[g[x][i]] && k>=0;k--)
					dp[x][j]=max_m(dp[x][j],dp[x][k],dp[g[x][i]][j-k]);
			}
		}
		
	f(i,0,min(sub[x],m)+1)
		dp[x][i].S+=w[x];
		
	pair<ll,ll> p;
	if(x!=1){
		f_(i,min(sub[x],m),1){
			p.F=dp[x][i-1].F,p.S=0;
			p.F+=(dp[x][i-1].S>0);
			dp[x][i]=max_m(dp[x][i],p,e);
		}
	}
	else{
		f_(i,min(sub[x],m),1){
			p.F=dp[x][i-1].F,p.S=0;
			p.F+=(dp[x][i-1].S>0);
			dp[x][i]=p;
		}
	}
}
void clear(){
	f(i,1,n+1)
		g[i].clear();
	f(i,1,n+1)
		f(j,0,min(m,sub[i])+1)
			dp[i][j].F=dp[i][j].S=0;
}

int main(){
	cin>>t;
	
	while(t--){
		clear();
		
		Gett(n,m);
		f(i,0,n) gett(b[i+1]);
		f(i,0,n){
			gett(w[i+1]);
			w[i+1]-=b[i+1];
		}
		f(i,1,n){
			Gett(x,y);
			g[x].pb(y);
			g[y].pb(x);
		}
		
		dfs(1,0);
		cout<<dp[1][m].F<<endl;
	}
}