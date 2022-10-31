#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,rt[100500];

#define wt(x,y) (nmsl[x]+b[x]*(y))
ll a[100500],b[100500],nmsl[100500];

#define N 100000
struct SB{
	#define md ((l+r)/2)
	int ls[10005000],rs[10005000],f[10005000],it;
	ll res;
	
	void add(int &id,int l,int r,int w){
		if(!id)id=++it;
		if(!f[id]){f[id]=w;return;}
		if(wt(f[id],md)>wt(w,md))swap(f[id],w);
		if(l==r)return;
		if(wt(w,l)<wt(f[id],l))add(ls[id],l,md,w);
		if(wt(w,r)<wt(f[id],r))add(rs[id],md+1,r,w);
	}
	
	void get(int &id,int l,int r,int x){
		if(!id)return;
		if(l<=x&&x<=r&&f[id])res=min(res,wt(f[id],x));
		if(l==r)return;
		if(x<=md)get(ls[id],l,md,x);else get(rs[id],md+1,r,x);
	}
	
	int hb(int x,int y,int l,int r){
		if(!x||!y)return x+y;
		if(l!=r){
			ls[x]=hb(ls[x],ls[y],l,md);
			rs[x]=hb(rs[x],rs[y],md+1,r);
		}
		if(f[y])add(x,l,r,f[y]);
		return x;
	}
}sb;

vector<int> v[100500];
void dfs(int x,int fa){
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		rt[x]=sb.hb(rt[x],rt[i],-N,N);
	}
	if(rt[x]){
		sb.res=1e18;
		sb.get(rt[x],-N,N,a[x]);
		nmsl[x]=sb.res;
	}
	sb.add(rt[x],-N,N,x);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);v[k].push_back(j);
	}
	dfs(1,0);
	for(i=1;i<=n;i++)cout<<nmsl[i]<<' ';
}