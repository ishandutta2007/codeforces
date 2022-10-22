#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+9;
ll n,m,par[N],cnt,c,mark[N],cmp[N],dis[N][2],l,r,mid,a[N],x,y,ans1,ans2;
vector<int> g[N];
vector<vector<int> > comp[N];
void dfs1(ll x,ll cm,ll dist){
	cmp[x]=cm;
	a[x]=c++;
	if(comp[cm].size()<=dist){
		vector<int> v;
		comp[cm].pb(v);
	}
	dis[x][0]=dist,dis[x][1]=comp[cm][dist].size();
	comp[cm][dist].pb(x);
	f(i,0,g[x].size()){
		dfs1(g[x][i],cm,dist+1);
	}
}
 
void pr(ll x,ll h,ll cm){
	ll p=dis[x][0]-h;
	l=0,r=comp[cm][p].size();
	while(l+1<r){
		mid=(l+r)/2;
		if(a[comp[cm][p][mid]]<a[x])
			l=mid;
		else r=mid;
	}
	ans1=a[comp[cm][p][l]];
	ans2=1e9;
	if(comp[cm][p].size()>l+1)
		ans2=a[comp[cm][p][l+1]];
}
ll solve(int h,int l1,int r1,int cm){
	l=-1,r=comp[cm][h].size();
	ll a1;
	while(l+1<r){
		mid=(l+r)/2;
		if(a[comp[cm][h][mid]]<l1)
			l=mid;
		else r=mid;
	}
	a1=r;
	l=-1,r=comp[cm][h].size();
	while(l+1<r){
		mid=(l+r)/2;
		if(a[comp[cm][h][mid]]<r1)
			l=mid;
		else r=mid;
	}
	return l-a1;
}
int main(){
	get(n);
	f(i,1,n+1){
		get(par[i]);
		g[par[i]].pb(i);
	}
	f(i,1,n+1){
		if(!par[i]){
			c=0;
			dfs1(i,cnt++,0);
		}
	}
	get(m);
	f(i,0,m){
		Get(x,y);
		if(dis[x][0]<y)
			cout<<0<<endl;
		else{
			ans1=0,ans2=0;
			pr(x,y,cmp[x]);
			cout<<solve(dis[x][0],ans1,ans2,cmp[x])<<endl;
		}
	}
}