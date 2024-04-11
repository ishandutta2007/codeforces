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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99;

int n,x,y,w[N];
vector<int> g[N];
ll lc,ans=1e12,sum,A[N];

void read(){
	cin>>n;
	f(i,1,n+1){ gett(w[i]); sum+=w[i]; }
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
}
void dfs(int x,int par,ll lcm){
	if(lcm>sum){
		cout<<sum;
		exit(0);
	}
	if(g[x].size()==1 && x!=1){
		if(lc==0) lc=lcm;
		else lc=lc*lcm/__gcd(lc,lcm);
	}
	if(lc>sum){
		cout<<sum;
		exit(0);
	}
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x,lcm*(g[x].size()-(x!=1)));
	A[x]=lcm;
}
void Get_ans(){
	f(i,2,n+1)
		if(g[i].size()==1)
			minm(ans,w[i]/(lc/A[i]));
}

main(){
	read();
	dfs(1,0,1);
	Get_ans();
	cout<<sum-ans*lc;
}