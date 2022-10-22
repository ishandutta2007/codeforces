#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;

int n,t,l,r,md,ansu,ansv,_u,_v,cnsth,cnstk,a[N],h[N],sz[N];
vector<int> vd;
vector<pair<int,int> > g[N];
vector<pair<int,pair<int,int> > > v;
pair<int,int> seg[N*2];

int G(int x){
	return (x<md ? -1 : 1);
}
void clear(int x){
	minm(x,n-1);
	x+=n;
	while(x){
		seg[x]=mp(-N,-N);
		x/=2;
	}
}
pair<int,int> Get(int l, int r){
	r++;
	minm(r,n);
	minm(l,n);
	pair<int,int> ans=mp(-N,-N);
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1)	maxm(ans,seg[l++]);
		if (r&1) maxm(ans,seg[--r]);
	}
	return ans;
}
void upd(int x,pair<int,int> p){
	x+=n;
	while(x){
		maxm(seg[x],p);
		x/=2;
	}
}
void dfsz(int x,int par){
	sz[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i].F==par){
			g[x].erase(g[x].begin()+i);
			i--;
		}
		else{
			h[g[x][i].F]=h[x]+1;
			dfsz(g[x][i].F,x);
			sz[x]+=sz[g[x][i].F];
		}
	}
}
void dfs2(int x,int k){
	v.pb(mp(h[x],mp(k,x)));
	f(i,0,g[x].size()){
		dfs2(g[x][i].F,k+(G(g[x][i].S)));
	}
	if(h[x]-cnsth<=r){
		int L=max(0,l-(h[x]-2*cnsth)),R=r-(h[x]-2*cnsth);
		if(L<=R){
			pair<int,int> p=Get(L,R);
			if(p.F+k-2*cnstk>=0){
				_u=x,_v=p.S;
			}
		}
	}
}
void dfs1(int x,int k){
	int u=0,mv=0;
	f(i,0,g[x].size()){
		if(sz[g[x][i].F]>sz[u]){
			u=g[x][i].F;
			mv=G(g[x][i].S);
		}
	}
	f(i,0,g[x].size()){
		if(g[x][i].F!=u){
			dfs1(g[x][i].F,k+G(g[x][i].S));
			f(j,h[x],h[x]+sz[g[x][i].F]+9){
				clear(j);
			}
		}
	}
	if(u) dfs1(u,k+mv);
	pair<int,int> p=Get(h[x]+l,h[x]+r);
	if(p.F-k>=0){
		_u=x,_v=p.S;
	}
	upd(h[x],mp(k,x));
	f(i,0,g[x].size()){
		if(g[x][i].F!=u){
			v.clear();
			cnstk=k,cnsth=h[x];
			dfs2(g[x][i].F,k+G(g[x][i].S));
			f(i,0,v.size()){
				upd(v[i].F,v[i].S);
			}
		}
	}
}
bool check(){
	_u=_v=0;
	dfs1(1,0);
	if(_u){
		ansu=_u,ansv=_v;
		return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(seg,seg+N,mp(-N,-N));
	cin>>n>>l>>r;
	f(i,1,n){
		int u,v,d;
		cin>>u>>v>>d;
		vd.pb(d);	
		g[u].pb(mp(v,d));
		g[v].pb(mp(u,d));
	}
	dfsz(1,0);
	sort(vd.begin(),vd.end());
	int l=-1,r=vd.size();
	while(l+1<r){
		fill(seg,seg+N,mp(-N,-N));
		int mid=(l+r)>>1;
		md=vd[mid];
		if(check()){
			l=mid;	
		}
		else{
			r=mid;
		}
	}	
	cout<<ansu<<" "<<ansv;
}