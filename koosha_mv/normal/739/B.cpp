#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=2e5+99;
ll n,ans[N],mark1[N],mark2[N],a[N],x,y;
vector<pair<ll,ll> > g[N];
void dfs1(ll x,ll dis){
	ll l=0,r=dis,mid;
	while(l+1<r){
		mid=(r+l)/2;
		if(mark2[dis]-mark2[mid]>a[x])
			l=mid;
		else
			r=mid;
	}
	ans[mark1[dis-1]]++;
	ans[mark1[l]]--;
	f(i,0,g[x].size()){
		mark1[dis+1]=g[x][i].first;
		mark2[dis+1]=mark2[dis]+g[x][i].second;
		dfs1(g[x][i].first,dis+1);
	}	
}
void dfs2(int x){
	f(i,0,g[x].size()){
		dfs2(g[x][i].first);
		ans[x]+=ans[g[x][i].first];
	}
}
int main(){
	cin>>n;mark1[1]=1;
	f(i,1,n+1) cin>>a[i];
	f(i,2,n+1){
		cin>>x>>y;
		g[x].pb(make_pair(i,y));
	}
	dfs1(1,1);
	dfs2(1);
	f(i,1,n+1) 
		cout<<ans[i]<<" ";
}