#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define F first
#define s second
const int N=2e5+9;
ll dp[N][2],n,x,y,f1[N][2],ans[N][4],m=-1,a;
vector<ll> g[N];
void dfs1(ll x,ll par){
	dp[x][0]=0,dp[x][1]=x;
	ll t=-1;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs1(g[x][i],x);
			if(dp[g[x][i]][0]+1>=dp[x][0]){
				dp[x][0]=dp[g[x][i]][0]+1;
				dp[x][1]=dp[g[x][i]][1];
			}
		}
		else t=i;
	}
	if(t>=0) g[x].erase(g[x].begin()+t);
}
void dfs2(ll x,ll par,ll dpar,ll apar){
	f_(i,g[x].size()-2,0){
		if(dp[g[x][i+1]][0]+1>=f1[g[x][i+1]][0])
			f1[g[x][i]][0]=dp[g[x][i+1]][0]+1,f1[g[x][i]][1]=dp[g[x][i+1]][1];
		else
			f1[g[x][i]][0]=f1[g[x][i+1]][0],f1[g[x][i]][1]=f1[g[x][i+1]][1];
	}
	ll mx=-1,amx=-1;
	f(i,0,g[x].size()){
		if(mx>f1[g[x][i]][0])
			f1[g[x][i]][0]=mx,f1[g[x][i]][1]=amx;
		if(dpar>=f1[g[x][i]][0])
			f1[g[x][i]][0]=dpar,f1[g[x][i]][1]=apar;
		dfs2(g[x][i],x,f1[g[x][i]][0]+1,f1[g[x][i]][1]);
		if(dp[g[x][i]][0]+1>=mx)
			mx=dp[g[x][i]][0]+1,amx=dp[g[x][i]][1];
	}
	vector<pair<int,int> > v;
	if(g[x].size()==0) return ;
	v.pb(make_pair(0,0)),v.pb(make_pair(0,0)),v.pb(make_pair(1,x)),v.pb(make_pair(dpar+1,apar));
	if(x==1) v[2]=make_pair(0,0);
	f(i,0,g[x].size()){
		v[0]=make_pair(dp[g[x][i]][0]+2,dp[g[x][i]][1]);
		sort(v.begin(),v.end());
	}
	ans[x][0]=v[1].F+v[2].F+v[3].F-3,ans[x][1]=v[1].s,ans[x][2]=v[2].s,ans[x][3]=v[3].s;
}
int main(){
	cin>>n;
	f(i,1,n){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs1(1,0);
	dfs2(1,0,0,1);
	f(i,1,n+1){
		if(ans[i][0]>m)
			m=ans[i][0],a=i;
	}
	cout<<ans[a][0]<<endl<<ans[a][1]<<" "<<ans[a][2]<<" "<<ans[a][3];
}