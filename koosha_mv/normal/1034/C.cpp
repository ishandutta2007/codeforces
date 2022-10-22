#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
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
 
const int N=1e6+2,M=130;
 
ll n,x,gc,ans=1,a[N],cnt[N],dp[M];
ll sum,sub[N];
vector<ll> c,g[N];
 
void dfs(int x){
	sub[x]=a[x];
	f(i,0,g[x].size()){
		dfs(g[x][i]);
		sub[x]+=sub[g[x][i]];
	}
}
void solve(ll x){
	int t=0;
	f(i,2,n+1)
		if(sub[i]%x==0)
			t++;
	if(t==sum/x-1)
		c.pb(sum/x);
}
 
int main(){
	cin>>n;
	f(i,1,n+1){ gett(a[i]); sum+=a[i]; gc=__gcd(gc,a[i]); }
	f(i,2,n+1){
		gett(x);
		g[x].pb(i);
	}
	dfs(1);
	f(i,1,n+1)
		cnt[min(1ll*(N-1),sub[1]/__gcd(sub[i],sub[1]))]++;
	f_(i,n,1)
		for(int j=i*2;j<=n;j+=i)
			cnt[j]+=cnt[i];
	f(i,1,n+1)
		if(cnt[i]==i)
			c.pb(i);
	f_(i,c.size()-1,0){
		dp[i]=1;
		f(j,i+1,c.size())
			if(c[j]%c[i]==0)
				dp[i]=dp[i]+dp[j];
	}
	cout<<dp[0];
}