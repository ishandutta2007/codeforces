#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;

int n,t,b[N],mark[N];
ll ans,a[N];
vector<int> v,g[N];
vector<pair<int,int> > ver;

void dfs(int x,int rt,int dist){
	f(i,0,g[x].size())
		dfs(g[x][i],rt,dist+1),a[x]+=max(a[g[x][i]],0ll);
	ans+=a[x];
	if(a[x]<0 || x==rt) ver.pb(mp(dist,x));
}
void dfs1(int x){
	v.pb(x);
	mark[x]=1;
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs1(g[x][i]);
}

int main(){
	cin>>n;
	f(i,1,n+1) get(a[i]);
	f(i,1,n+1){
		gett(b[i])
		if(0<b[i]) g[b[i]].pb(i);
	}
	f(i,1,n+1)
		if(b[i]==-1)
			dfs(i,i,0);
	sort(ver.begin(),ver.end());
	reverse(ver.begin(),ver.end());
	f(i,0,ver.size())
		dfs1(ver[i].S);
	cout<<ans<<endl;
	f_(i,n-1,0) cout<<v[i]<<" ";
}