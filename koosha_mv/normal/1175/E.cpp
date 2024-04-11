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
const int N=5e5+99;
ll n,m,a[N],mx,x,y,mark[N],cnt,ans,b1,b2,dst[N];
vector<ll> v[N],g[N],dist[N];
void dfs(int x,int dis){
	mark[x]=1,dst[x]=dis;
	dist[dis].pb(x);
	a[x]=cnt++;
	f(i,0,g[x].size())
		dfs(g[x][i],dis+1);
}
ll GET(int d,int x){
	ll l=0,r=dist[d].size(),mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(a[dist[d][mid]]<=x) l=mid;
		else r=mid;
	}
	return dist[d][l];
}
ll binary_search_tree(){
	ll l=-1,r=dst[b1],mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(GET(mid,a[b1])>=b2) l=mid;
		else r=mid;
	}
	if(l==-1) return l;
	return dst[b1]-l;
}
int main(){
	Get(n,m);
	f(i,0,n){
		Get(x,y);
		v[x].pb(y);
	}
	f(i,0,N-1){
		f(j,0,v[i].size())
			maxm(mx,v[i][j]);
		if(mx>i)
			g[mx].pb(i);
	}
	f_(i,N-2,0){
		if(mark[i]==0){
			dfs(i,0);
		}
	}
	f(i,0,m){
		Get(b1,b2);
		ans=binary_search_tree();
		cout<<ans<<endl;
	}
}