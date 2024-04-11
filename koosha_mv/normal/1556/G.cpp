#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define P pair<pair<ll,ll>,ll>
 
const int N=2e6+99,M=1e7+99;
 
ll n,q,cnt=1,a[N],p[N][3],par[N];
map<ll,ll> T;
vector<ll> ans;
vector<pair<ll,ll> > intvl;
vector<int> g[N];
vector<pair<pair<ll,ll>,ll> > v,V;

void Add_edge(int u,int v){
	if(u>v) swap(u,v);
	g[u].pb(v);
}
ll Get_par(ll x){
	if(par[x]<0) return x;
	return par[x]=Get_par(par[x]);
}
void merge(ll u,ll v){
	u=Get_par(u),v=Get_par(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
ll first_par(ll id){
	while(T.count(id)==0){
		id/=2;
	}
	return T[id];
}
void Get(ll id,ll L,ll R,ll l,ll r){
	if(id==1) v.clear();
	if(R<=L) return ;
	if(R<=l || r<=L) return ;
	if(L<=l && r<=R){
		if(!T[id]){
			T[id]=cnt++;
		}
		v.pb(mp(mp(l,r),id));
		return ;
	}
	ll mid=(l+r)/2;
	Get(id*2+0,L,R,l,mid);
	Get(id*2+1,L,R,mid,r);
}
void Add_intvl(P p){
	p.S=T[p.S];
	V.pb(p);
}
void Add_vertex(ll id){
	ll x=T[id];
	f(i,0,g[x].size()){
		merge(x,g[x][i]);	
	}
}
void make_graph(ll L,ll R,ll l,ll r){
	int v=-1;
	ll mid=(l+r)/2,Mid=L;
	if(L==R || l==r) return ;
	f(i,L,R){
		if(V[i].F.S<=mid){
			Mid=i+1;
		}
		if(V[i].F.F>=mid) V[i].F.F-=mid,V[i].F.S-=mid;
	}
	int p=Mid;
	f(i,L,Mid){
		while(p<R && V[p].F.S<=V[i].F.F){
			p++;
		}
		while(p<R && V[p].F.F<V[i].F.S){
			Add_edge(V[i].S,V[p].S);
			p++;
		}
		p--;
	}
	make_graph(L,Mid,l,mid);
	make_graph(Mid,R,l,mid);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(par,par+N,-1);
	cin>>n>>q;
	intvl.pb(mp(0,0));
	f(i,0,q){
		string s;
		cin>>s>>p[i][1]>>p[i][2];
		p[i][0]=(s[0]=='b');
		
		if(p[i][0]){
			intvl.pb(mp(p[i][1],++p[i][2]));
			Get(1,p[i][1],p[i][2],0,(1ll<<n));
			f(j,0,v.size()){
				Add_intvl(v[j]);
			}
		}
	}
	intvl.pb(mp((1ll<<n),(1ll<n)));
	sort(intvl.begin(),intvl.end());
	f(i,0,intvl.size()-1){
		Get(1,intvl[i].S,intvl[i+1].F,0,(1ll<<n));
		f(j,0,v.size()){
			Add_intvl(v[j]);
		}
	}
	sort(V.begin(),V.end());
	make_graph(0,V.size(),0,(1ll<<n));
	f(i,0,intvl.size()-1){
		Get(1,intvl[i].S,intvl[i+1].F,0,(1ll<<n));
		f(j,0,v.size()){
			Add_vertex(v[j].S);
		}
	}
	f_(i,q-1,0){
		if(p[i][0]==0){
			int _u=first_par(p[i][1]+(1ll<<n)),_v=first_par(p[i][2]+(1ll<<n));
			if(Get_par(_u)==Get_par(_v)){
				ans.pb(1);
			}
			else{
				ans.pb(0);
			}
		}
		else{
			Get(1,p[i][1],p[i][2],0,(1ll<<n));
			f(j,0,v.size()){
				Add_vertex(v[j].S);
			}
		}
	}
	f_(i,ans.size()-1,0) cout<<ans[i]<<'\n';
}
/*
6 3
block 12 26
block 32 46
ask 1 54
*/