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
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,mod=1e9+7;

int n,p,u,v,t,e,ans=1,mark[N];
vector<int> g[N];

void dfs(int u){
	t++,e+=g[u].size();
	mark[u]=1;
	f(i,0,g[u].size()){
		if(!mark[g[u][i]])
			dfs(g[u][i]);
		if(g[u][i]==u)
			p=1;
	}
}

int main(){
	cin>>n;
	f(i,1,n+1){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,2*n)
		if(!mark[i]){
			e=0,t=0,p=2;
			dfs(i);
			(e==t*2 ? ans=ans*p%mod : ans=1ll*ans*t%mod);
		}
	cout<<ans;
}