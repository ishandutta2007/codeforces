#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define get(x) scanf("%I64d",&x)
#define gett(x) scanf("%d",&x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,lg=18;

int n,m,q,c,s[N],t[N],h[N],par[lg][N],bpar[lg][N];
vector<int> g[N],seg[2*N];

bool is_par(int u,int v){
	return (s[u]<=s[v] && s[v]<t[u]);
}
void upd(int u,int v){
	if(bpar[0][u]==N || h[v]<h[bpar[0][u]])
		bpar[0][u]=v;	
}
void make_bpar(){
	f(i,1,n+1)
		f(j,1,lg)
			bpar[j][i]=bpar[j-1][bpar[j-1][i]];
}
void Add(int u,int v){
	int x;
	x=s[u]+n;
	while(x){
		//if(u==4 && v==7) cout<<"X :: "<<x<<endl;
		seg[x].pb(s[v]);
		x/=2;
	}
	x=s[v]+n;
	while(x){
		seg[x].pb(s[u]);
		x/=2;
	}
}
int lca(int u,int v){
	if(u>v) swap(u,v);
	if(is_par(u,v)) return u;
	f_(i,lg-1,0){
		if(!is_par(par[i][u],v)){
			u=par[i][u];
		}
	}	
	return par[0][u];
}
void dfs1(int x){
	s[x]=c++;
	if(par[0][x]==0) par[0][x]=x;
	f(i,1,lg) par[i][x]=par[i-1][par[i-1][x]];
	f(i,0,g[x].size()){
		h[g[x][i]]=h[x]+1;
		par[0][g[x][i]]=x;
		dfs1(g[x][i]);
	}
	t[x]=c;
}
void dfs2(int x){
	upd(x,x);
	f(i,0,g[x].size()){
		dfs2(g[x][i]);
		upd(x,bpar[0][g[x][i]]);
	}
	//cout<<x<<" : "<<bpar[0][x]<<endl;
}
bool check(int x,int l,int r){
	if(seg[x].size()==0 || seg[x].back()<l) return 0;
	return *lower_bound(seg[x].begin(),seg[x].end(),l)<r;
}
int is_path(int u,int v){
	int ans=0,l=s[u],r=t[u];
	//erorp(mp(l,r));
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1){
			int x=l++;
			ans|=check(x,s[v],t[v]);
		}
		if(r&1){
			int x=--r;
			ans|=check(x,s[v],t[v]);
		}
	}
	//cout<<u<<" "<<v<<" : "<<ans<<endl;
	return 1-ans;
}
pair<int,int> solve(int u,int v){
	int ans=0;
	if(!is_par(bpar[lg-1][v],u)) return mp(-1,-1);
	f_(i,lg-1,0){
		if(!is_par(bpar[i][v],u)){
			ans+=(1<<i);
			v=bpar[i][v];
		}
	}
	return mp(v,ans);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	f(i,0,N) bpar[0][i]=N;
	
	cin>>n;
	f(i,2,n+1){
		int x;
		cin>>x;
		g[x].pb(i);
	}
	
	dfs1(1);
	
	cin>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		Add(u,v);
		upd(u,lca(u,v));
		upd(v,lca(u,v));
	}
	
	dfs2(1);
	make_bpar();
	f(i,1,2*n) sort(seg[i].begin(),seg[i].end());
	
	cin>>q;
	f(i,0,q){
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		if(is_par(u,v)){
			if(solve(u,v).S==-1) cout<<-1<<endl;
			else cout<<solve(u,v).S+1<<endl;
		}
		else{
			pair<int,int> v1=solve(lca(u,v),u),v2=solve(lca(u,v),v);
			if(v1.F==-1 || v2.F==-1) cout<<-1<<endl;
			else{
				cout<<v1.S+v2.S+is_path(v1.F,v2.F)+1<<endl;
			}
		}
	}
}