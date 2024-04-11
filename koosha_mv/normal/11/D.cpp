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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second

const int N=19;

int n,m,u,v,g[N][N];
ll ans,dp[(1<<N)][N];

void calc(int mask,int u){
	if(dp[mask][u]>0) return ;
	dp[mask][u]=0;
	if(!is_bit(mask,u)) return ;
	f(i,0,n)
		if(g[u][i] && is_bit(mask,i))
			dp[mask][u]+=dp[mask-(1<<u)][i];
}
void solve(int u){
	f(i,0,(1<<N)) f(j,0,N) dp[i][j]=-1;
	
	f(i,0,n){
		f(j,0,n) dp[(1<<i)][j]=0;
		if(g[u][i])
			dp[(1<<i)][i]=1;
	}
	f(mask,0,(1<<u))
			f(j,0,u){
				calc(mask,j);
				if(g[u][j] && mask!=(1<<j))
					ans+=dp[mask][j];
			}
}

int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(u,v);
		--u,--v;
		g[u][v]=g[v][u]=1;
	}
	f_(i,n-1,0)
		solve(i);
	cout<<ans/2<<endl;
}