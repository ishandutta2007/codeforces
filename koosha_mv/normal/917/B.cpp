#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=102;

int n,t,m,x,y,dp[N][N][26];
char s;
vector<pair<int,int> > g[N];

int solve(int u,int v,int c){
	if(dp[u][v][c]>=0) return dp[u][v][c];
	dp[u][v][c]=0;
	f(i,0,g[u].size())
		if(g[u][i].S>=c)
			dp[u][v][c]=(dp[u][v][c] || (!solve(v,g[u][i].F,g[u][i].S)));
	return dp[u][v][c];		
}
int main(){
	f(i,0,N) f(j,0,N) f(k,0,26) dp[i][j][k]=-1;
	cin>>n>>m;
	f(i,0,m){
		cin>>x>>y>>s;
		g[x].pb(mp(y,s-'a'));
	}
	f(i,1,n+1){
		f(j,1,n+1){
			solve(i,j,0);
			cout<<(dp[i][j][0]==1 ? 'A' : 'B');
		}
		cout<<endl;
	}
}