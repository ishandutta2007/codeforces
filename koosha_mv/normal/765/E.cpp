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
#define S second
#define F first
const int N=2e5+9;
ll n,dp[N],x,y,t,mark[N],tdd,ans,pr,k;
vector<ll> g[N],u,prr;
void dfs(int x,int par){
	vector<int> v;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			v.pb(dp[g[x][i]]);
		}
	}
	sort(v.begin(),v.end());
	//cout<<" x : "<<x<<endl;
	//f(i,0,v.size()) cout<<v[i]<<" "; 
	//cout<<endl;
	if(v.size()>0 &&  v[0]!=v[v.size()-1]){
		if(x!=pr) k=-1;
		prr.pb(x);return;}
	if(v.size()>0) dp[x]=v[0]+1;
}	
int main(){
	get(n);
	f(i,1,n){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	pr=1;
	dfs(1,0);
	f(i,0,n+1) dp[i]=0;
	if(prr.size()>0) pr=prr[0];
	k=0;
	dfs(pr,0);
	if(k==-1) cout<<-1;
	else{
		f(i,0,g[pr].size()){
			if(mark[dp[g[pr][i]]+1]==0) mark[dp[g[pr][i]]+1]=1,u.pb(dp[g[pr][i]]+1);
		}
		if(u.size()<=2){
			ans+=u[0];
			if(u.size()==2)
				ans+=u[1];
			while(ans%2==0)
				ans/=2;
			cout<<ans;
		}
		else
			cout<<-1;
	}
}