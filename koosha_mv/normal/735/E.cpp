#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=105,K=23,mod=1e9+7;

int n,t,u,v,k,ans,C[K][K],dp[N][K][K]; // mxm & maxV
vector<int> g[N];

void dfs(int x,int par){
	dp[x][0][0]=1;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			f(i,0,k+1)
				f(j,0,k+1)
					C[i][j]=0;
			f(a1,0,k+1)
				f(a2,0,k+1)
					f(b1,0,k+1)
						f(b2,0,k+1)
							Add(C[max(a1,b1)][max(a2,b2)],1ll*dp[x][a1][a2]*dp[g[x][i]][b1][b2]%mod);
			f(a1,0,k+1)
				f(a2,0,k+1)
					dp[x][a1][a2]=C[a1][a2];
		}
		f(s,0,k+1) f(j,0,k+1) C[s][j]=dp[x][s][j],dp[x][s][j]=0;
		f(s,0,k+1)
			f(j,0,k+1){
				if(s-1>=j || j==0){
					if(s) Add(dp[x][s-1][0],C[s][j]);
					else Add(dp[x][0][1],C[s][j]);
				}
				else
					Add(dp[x][max(s-1,0)][j+1],C[s][j]);
			}
		f(i,0,k)
			f(j,0,k+2)
				Add(dp[x][k][0],dp[x][i][j]);
}

int main(){
	cin>>n>>k;
	if(k==0) return cout<<1,0;
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	f(i,0,k+1)
		Add(ans,dp[1][i][0]);
	cout<<ans;
}
/*
5 1
1 2
1 3
1 4
1 5
*/