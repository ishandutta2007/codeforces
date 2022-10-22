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
ll n,m,k,sp[N],x,y,dis[N],mark[N],anss,sfr,mark2[N],dis2[N],mx[N],a[N],l,r,mid;
vector<ll> g[N],o;
pair<ll,ll> ans[N];
ll bfs(vector<ll> v,ll dist){
	vector<ll> u;
	f(i,0,v.size()){
		dis[v[i]]=dist;
		f(j,0,g[v[i]].size()){
			if(mark[g[v[i]][j]]==0){
				u.pb(g[v[i]][j]);
				mark[g[v[i]][j]]=1;
			}
		}
	}
	if(u.size()>0) bfs(u,dist+1);
}
ll bfs2(vector<ll> v,ll dist){
	vector<ll> u;
	f(i,0,v.size()){
		dis2[v[i]]=dist;
		f(j,0,g[v[i]].size()){
			if(mark2[g[v[i]][j]]==0){
				u.pb(g[v[i]][j]);
				mark2[g[v[i]][j]]=1;
			}
		}
	}
	if(u.size()>0) bfs2(u,dist+1);
}
int main(){
	cin>>n>>m>>k;
	f(i,0,k){
		get(x);
		sp[i]=x;
	}
	f(i,0,m){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,1,n+1) a[i]=-1;
	mark[1]=1;o.pb(1);
	bfs(o,0);
	o.clear();o.pb(n);
	mark2[n]=1;
	bfs2(o,0);
	f(i,0,k)
		ans[i].F=dis[sp[i]],ans[i].S=dis2[sp[i]];
	sort(ans,ans+k);
	f_(i,k-1,0)
		mx[i]=max(mx[i+1],ans[i].S);
	f(i,0,k-1){
		l=i+1,r=k-1;
		while(l+1<r){
			mid=(l+r)/2;
			if(ans[mid].F+ans[i].S<ans[i].F+mx[mid]) l=mid;
			else r=mid;
		}
		maxm(anss,min(ans[i].S+ans[l].F,ans[i].F+mx[l]));
		maxm(anss,min(ans[i].S+ans[r].F,ans[i].F+mx[r]));
	}
	anss++;
	minm(anss,dis[n]);
	cout<<anss;
}