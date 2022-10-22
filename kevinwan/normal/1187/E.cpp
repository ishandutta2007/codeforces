#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 1.1e6+10;
const ll mod = 1e9+7;
vi g[mn];

ll s[mn],d[mn],u[mn];

void dfs1(int x,int p){
	s[x]=1;
	for(int y:g[x])if(y!=p){
		dfs1(y,x);
		s[x]+=s[y];
		d[x]+=d[y];
	}
	d[x]+=s[x];
}

void dfs2(int x,int p){
	for(int y:g[x])if(y!=p){
		u[y]=u[x]+d[x]-d[y]-s[x]+(s[1]-s[y]);
		dfs2(y,x);
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(1,0);
	dfs2(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,u[i]+n);
	printf("%lld\n",ans);
}