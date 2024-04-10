#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1e5+5;
const ll inf=1e18;
int n,k,g[N],w[N],ans;
int d[N],ds,fa[N];
ll pre[N],suf[N];
vector<int>e[N];
int pl,pr,wr;
ll ad,mx;
struct nod{
	int l,r;
	ll ad,m_c,mx,mx2,q;
	void add(ll x){
		ad+=x;
		mx+=x;
		m_c+=x;
		q+=x;
	}
}t[N*4];
ll get(int v,int l,int r,ll mx){
	if(l==r)return mx-t[v].mx2;
	int m=l+r>>1;
	if(mx>=t[v*2].mx)return min(mx-t[v*2].mx2,get(v*2+1,m+1,r,mx));
	return min(t[v].q,get(v*2,l,m,mx));
}
void up(int v,int l,int r){
	t[v].q=get(v*2+1,l+r+2>>1,r,t[v*2].mx);
	t[v].mx=max(t[v*2].mx,t[v*2+1].mx);
	t[v].m_c=min(t[v*2].m_c,t[v*2+1].m_c);
}
void B(int v,int l,int r){
	if(l==r){
		t[v].mx2=t[v].mx=suf[l];
		return;
	}
	int m=l+r>>1;
	B(v*2,l,m);B(v*2+1,m+1,r);
	up(v,l,r);
	t[v].mx2=max(t[v*2].mx2,t[v*2+1].mx2);
}
void dw(int v){
	t[v*2].add(t[v].ad);
	t[v*2+1].add(t[v].ad);
	t[v].ad=0;
}
void add(int v,int l,int r){
	if(pl<=l){
		t[v].add(ad);
		return;
	}
	if(t[v].ad)dw(v);
	int m=l+r>>1;
	if(pl<=m)add(v*2,l,m),t[v*2+1].add(ad);else add(v*2+1,m+1,r);
	up(v,l,r);
}
int find_r(int v,int l,int r){
	if(l==r)return r;
	if(t[v].ad)dw(v);
	int m=l+r>>1;
	return t[v*2+1].m_c<=k?find_r(v*2+1,m+1,r):find_r(v*2,l,m);
}
ll qmx(int v,int l,int r,int x){
	if(x<=l)return t[v].mx;
	if(t[v].ad)dw(v);
	int m=l+r>>1;
	if(x<=m)return max(t[v*2+1].mx,qmx(v*2,l,m,x));
	return qmx(v*2+1,m+1,r,x);
}
void find_ans(int v,int l,int r){
	if(pl<=l&&r<=pr){
		ll a=get(v,l,r,mx);
		if(a>k)return;
		wr=max(wr,l);
	}
	if(l==r)return;
	if(t[v].ad)dw(v);
	int m=l+r>>1;
	if(pr>m){
		ll las=mx;
		if(pl<=m)mx=max(mx,qmx(v*2,l,m,pl));
		find_ans(v*2+1,m+1,r);
		mx=las;
	}
	if(wr<m&&pl<m)find_ans(v*2,l,m);
}
void dfs(int x){
	if(fa[x])pl=fa[x]-1,ad=pre[x-1]-pre[pl],add(1,1,n);
	pl=x;pr=min(find_r(1,1,n)+1,n);wr=x;mx=-inf;
	find_ans(1,1,n);
	ans=max(ans,wr-x+1);
	for(int i:e[x])dfs(i);
	if(fa[x])pl=fa[x]-1,ad=pre[pl]-pre[x-1],add(1,1,n);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	fo(i,1,n-1)cin>>w[i];
	fo(i,1,n)cin>>g[i];
	fo(i,1,n)pre[i]=pre[i-1]+g[i]-w[i],suf[i]=suf[i-1]+g[i]-w[i-1];
	fd(i,1,n){
		for(;ds&&pre[d[ds]-1]>=pre[i-1];)--ds;
		if(ds)fa[i]=d[ds],e[fa[i]].push_back(i);
		d[++ds]=i;
	}
	B(1,1,n);
	fd(i,1,n)if(!fa[i])dfs(i);
	cout<<ans;
}