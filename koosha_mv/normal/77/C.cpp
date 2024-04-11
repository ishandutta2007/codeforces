#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+9;
ll n,dp[N],a[N],x,y,s;
vector<int> g[N];
void dfs(int x,int par){
	dp[x]=1,a[x]--;
	vector<ll> v;
	ll sum1=0;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			v.pb(dp[g[x][i]]);
			sum1+=a[g[x][i]];
		}
	}
	sort(v.begin(),v.end());
	f_(i,v.size()-1,0){
		if(a[x]){
			a[x]--;
			dp[x]++;
			dp[x]+=v[i];
		}
	}
	dp[x]+=min(a[x],sum1)*2;
	a[x]-=min(a[x],sum1);
}
int main(){
	cin>>n;
	f(i,1,n+1) get(a[i]);
	f(i,1,n){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	cin>>s;a[s]++;
	dfs(s,0);
	cout<<--dp[s];
}