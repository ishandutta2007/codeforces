#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=13e5+99,M=3e5+99,lg=20;
 
int n,q,cnt,a[M],h[M],lazy[N];
pair<int,int> par[lg][M];
vector<pair<int,int> > g[M];
 
int dist(int u,int v){
	if(abs(u-v)==1 && a[min(u,v)]!=-1) return a[min(u,v)];
	int res=0;
	if(h[u]>h[v]) swap(u,v);
	f_(l,lg-1,0){
		if(h[u]<=h[par[l][v].F]){
			maxm(res,par[l][v].S);
			v=par[l][v].F;
		}
	}
	if(u==v) return res;
	f_(l,lg-1,0){
		if(par[l][u].F!=par[l][v].F){
			maxm(res,par[l][u].S);
			maxm(res,par[l][v].S);
			u=par[l][u].F;
			v=par[l][v].F;
		}
	}
	maxm(res,par[0][u].S);
	maxm(res,par[0][v].S);
	return res;
}
void dfs(int u,int p,int val){
	par[0][u]={p, val};
	f(l,1,lg){
		par[l][u].F=par[l-1][par[l-1][u].F].F;
		par[l][u].S=max(par[l-1][u].S,par[l-1][par[l-1][u].F].S);
	}
	for(auto v : g[u]){
		if(v.F==p) continue ;
		h[v.F]=h[u]+1;
		dfs(v.F,u,v.S);
	}
}
 
 
struct node{
	int fst,lst,ans,def,l,r,lc,rc,d;
	node(){
		ans=def=d=0;
		lc=-1,rc=N;
		lst=-1,fst=N;
	}	
	void upd(int x){
		if(x==0){
			ans=d=0;
			lc=-1,rc=N;
			lst=-1,fst=N;
		}
		else{
			lc=((l+r)>>1)-1;
			rc=(l+r)>>1;
			d=dist(lc,rc);
			fst=l;
			lst=r-1;
			ans=def;
		}
	}
} seg[N];
 
void upd(int id){
	int u=id<<1,v=id<<1|1;
	seg[id].ans=max(seg[u].ans,seg[v].ans);
	seg[id].fst=min(seg[u].fst,seg[v].fst);
	seg[id].lst=max(seg[u].lst,seg[v].lst);
	if(seg[id].lc!=seg[u].lst || seg[id].rc!=seg[v].fst){
		seg[id].d=0;
		seg[id].lc=seg[u].lst;
		seg[id].rc=seg[v].fst;
		if(seg[id].lc!=-1 && seg[id].rc<N){
			seg[id].d=dist(seg[id].lc,seg[id].rc);
		}
	}
	maxm(seg[id].ans,seg[id].d);
}
void build(int id=1,int l=0,int r=n){
	seg[id].l=l;
	seg[id].r=r;
	if(l+1==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid,r);
	seg[id].def=max(seg[id<<1].def,seg[id<<1|1].def);
	maxm(seg[id].def,dist(mid-1,mid));
}
void shift(int id){
	if(lazy[id]==-1) return;
	lazy[id<<1]=lazy[id];
	lazy[id<<1|1]=lazy[id];
	seg[id<<1].upd(lazy[id]);
	seg[id<<1|1].upd(lazy[id]);
	lazy[id]=-1;
}
void change(int id,int l,int r,int L,int R,int val){
	//cout<<id<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if(r<=L || R<=l) return ;
	if(L<=l && r<=R){
		lazy[id]=val;
		seg[id].upd(val);
		return ;
	}
	int mid=(l+r)>>1;
	shift(id);
	change(id<<1,l,mid,L,R,val);
	change(id<<1|1,mid,r,L,R,val);
	upd(id);
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(lazy,lazy+N,-1);
	fill(a,a+M,-1);
	cin>>n>>q;
	f(i,1,n){
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dfs(0,0,0);
	f(i,0,n-1) a[i]=dist(i,i+1);
	build();
	f(i,0,q){
		int t,l,r,x;
		cin>>t;
		if(t==1){
			cin>>l>>r; l--;
			change(1,0,n,l,r,1);
		}
		if(t==2){
			cin>>l>>r; l--;
			change(1,0,n,l,r,0);
		}
		if(t==3){
			cin>>x; x--;
			if(seg[1].lst==-1 || (seg[1].fst==seg[1].lst && seg[1].fst==x)){
				cout<<-1<<'\n';
			}
			else{
				cout<<max(seg[1].ans,dist(x,seg[1].fst))<<'\n';
			}
		}
	}
}