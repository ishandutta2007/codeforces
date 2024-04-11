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

const int N=5e5+99;

int n,x,y,rt=1,ans,dp1[N],dp2[N];//1:rt nbshe 2:kol
vector<int> g[N];

void dfs(int x,int par){
	vector<int> v1,v2;
	f(i,0,3) v1.pb(0),v2.pb(0);
	
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			v1[0]=dp1[g[x][i]];
			v2[0]=dp2[g[x][i]];
			sort(v1.begin(),v1.end());
			sort(v2.begin(),v2.end());
			
			maxm(dp1[x],dp2[g[x][i]]);
			maxm(dp2[x],dp1[g[x][i]]);
		}
	}
	dp1[x]+=(g[x].size()-2+(x==rt));
	dp2[x]++;
	maxm(dp2[x],dp1[x]);
	
	if(g[x].size()>2 || x==rt){
		maxm(ans,v1[1]+v1[2]+1);
		maxm(ans,v2[1]+v2[2]+int(g[x].size())-2);
	}
}
int main(){
	cin>>n;
	
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	
	for(;g[rt].size()==1;rt++){}
	
	dfs(rt,0);
	cout<<ans;
}