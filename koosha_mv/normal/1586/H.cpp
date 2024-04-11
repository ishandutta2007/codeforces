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

const int N=2e5+99,lg=20;

int n,q,te,a[N],e[N],s[N],t[N],dsu[N];
vector<pair<int,int> > g[N];
vector<pair<int,pair<int,int> > > edge;
pair<int,int> res[N],ans[N],par[lg][N];

int is_par(int u,int v){
	return s[u]<=s[v] && t[v]<=t[u];
}
int dist(int u,int v){
	int ans=0;
	f_(i,lg-1,0){
		if(!is_par(par[i][u].F,v)){
			maxm(ans,par[i][u].S);
			u=par[i][u].F;
		}
	}
	f_(i,lg-1,0){
		if(!is_par(par[i][v].F,u)){
			maxm(ans,par[i][v].S);
			v=par[i][v].F;
		}
	}
	if(!is_par(u,v)){
		maxm(ans,par[0][u].S);
	}
	if(!is_par(v,u)){
		maxm(ans,par[0][v].S);
	}
	return ans;
}
int Get_par(int u){
	if(dsu[u]<0) return u;
	return dsu[u]=Get_par(dsu[u]);
}
void merge(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(dsu[u]>dsu[v]) swap(u,v);
	if(e[ans[u].F]!=e[ans[v].F]){
		if(e[ans[u].F]<e[ans[v].F]){
			ans[u]=ans[v];
		}
	}
	else{
		maxm(ans[u].S,ans[v].S);
		maxm(ans[u].S,dist(ans[u].F,ans[v].F));
	}
	dsu[u]+=dsu[v];
	dsu[v]=u;
}
void dfs(int x){
	s[x]=te++;
	f(i,1,lg){
		pair<int,int> p1=par[i-1][x],p2=par[i-1][p1.F];
		par[i][x]=mp(p2.F,max(p1.S,p2.S));
	}
	f(i,0,g[x].size()){
		if(g[x][i].F!=par[0][x].F){
			par[0][g[x][i].F]=mp(x,g[x][i].S);
			dfs(g[x][i].F);
		}
	}
	t[x]=te++;
}
void read(){
	cin>>n>>q;	
	f(i,1,n+1) cin>>e[i];
	f(i,1,n){
		int u,v,c,t;
		cin>>u>>v>>c>>t;		
		g[u].pb(mp(v,t));
		g[v].pb(mp(u,t));
		edge.pb(mp(c,mp(u,v)));
	}
	f(i,0,q){
		int u,x;
		cin>>x>>u;
		edge.pb(mp(x,mp(-i,u)));
	}
	f(i,1,n+1){
		dsu[i]=-1;
		ans[i]=mp(i,0);
	}
	sort(edge.begin(),edge.end());
	reverse(edge.begin(),edge.end());
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	read();
	par[0][1]=mp(1,0);
	dfs(1);
	f(i,0,edge.size()){
		if(edge[i].S.F>0){
			merge(edge[i].S.F,edge[i].S.S);
		}
		else{
			int ind=-edge[i].S.F,u=edge[i].S.S,par=Get_par(u),len=dist(u,ans[par].F);
			res[ind]=mp(e[ans[par].F],max(len,ans[par].S));
		}
	}
	f(i,0,q){
		cout<<res[i].F<<" "<<res[i].S<<endl;
	}
}