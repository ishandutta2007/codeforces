#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
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
const int N=1e5+9,M=4e6+9,k=22;
ll n,u,v,p,X[N],t[N],li[N],tdd[M],hz[M],a[M],dp[N];
ll T,l,r,mid,c;
vector<int> g[N];
void add(ll x,ll y){
	a[x]+=y;
	p=(1<<k),c=(1<<k)-y;
	f_(i,k-1,0){
		if(c>=(1<<i)){
			c-=(1<<i);
			p-=(1<<i);
			hz[p]+=x*y;
			tdd[p]+=x;
		}
	}
}

void del(ll x,ll y){
	a[x]-=y;
	p=(1<<k),c=(1<<k)-y;
	f_(i,k-1,0){
		if(c>=(1<<i)){
			c-=(1<<i);
			p-=(1<<i);
			hz[p]-=x*y;
			tdd[p]-=x;
		}
	}
}

ll check(ll x){
	ll ans=0;
	c=x,p=0;
	f_(i,k-1,0){
		if(c>=(1<<i)){
			c-=(1<<i);
			p+=(1<<i);
			ans+=hz[p];
		}
	}
	return ans;
}

ll check2(ll x){
	ll ans=0;
	c=x,p=0;
	f_(i,k-1,0){
		if(c>=(1<<i)){
			c-=(1<<i);
			p+=(1<<i);
			ans+=tdd[p];
		}
	}
	return ans;
}

ll solve_ver(ll x){
	ll ans;
	if(x<=0) return 0;
	l=0,r=2e6;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)<=x) l=mid;
		else r=mid;
	}
	x-=(check(l));
	ans=check2(l);
	ans+=min(x/(l+1),tdd[l+1]);
	return ans;
}

void dfs_get_ans(int x,ll suml){
	add(X[x],t[x]);
	dp[x]=solve_ver(T-suml*2);
	f(i,0,g[x].size())
		dfs_get_ans(g[x][i],suml+li[g[x][i]]);
	del(X[x],t[x]);
}

void dfs_dp(int x){
	vector<ll> v;
	f(i,0,3) v.pb(0);
	f(i,0,g[x].size()){
		dfs_dp(g[x][i]);
		v[0]=dp[g[x][i]];
		sort(v.begin(),v.end());
	}
	if(x==1)
		maxm(dp[x],v[2]);
	maxm(dp[x],v[1]);
}
int main(){
	cin>>n>>T;
	f(i,1,n+1)
		gett(X[i]);
	f(i,1,n+1)
		gett(t[i]);
	f(i,2,n+1){
		Gett(u,v);
		g[u].pb(i);
		li[i]=v;
	}
	dfs_get_ans(1,0);
	dfs_dp(1);
	cout<<dp[1];
}