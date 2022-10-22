#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+9;
ll a,b,n,x,y,dp1[N],dp2[N];
vector<int> g[N];
void dfs(int x,int par){
	vector<int> v;
	v.pb(0),v.pb(0),v.pb(0);
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			dp2[x]+=dp1[g[x][i]];
			v[0]=dp1[g[x][i]]-dp2[g[x][i]];
			sort(v.begin(),v.end());
		}
	}
	dp1[x]=dp2[x]-v[1]-v[2]+1;
	dp2[x]-=v[2];
	minm(dp1[x],dp2[x]+1);
	if(g[x].size()==1 && x!=1) dp1[x]=1,dp2[x]=0;
}
int main(){
	cin>>n>>a>>b;
	f(i,1,n){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	if(a<=b){
		dfs(1,0);
		cout<<(dp1[1]-1)*b+(n-dp1[1])*a;
	}
	else{
		f(i,1,n+1){
			if(g[i].size()==n-1)
				return cout<<a+b*(n-2),0;
		}
		cout<<b*(n-1);
	}
}