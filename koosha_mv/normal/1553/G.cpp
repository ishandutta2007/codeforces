#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99;
 
int n,q,c=1,a[N],p[N],par[N],vis[N],mark[N];
vector<int> d[N],g[N];
vector<pair<int,int> > v ;
 
void pre(){
	f(i,2,N){
		p[i]^=1;
		if(p[i]){
			for(int j=i;j<N;j+=i)
				p[j]=1,d[j].pb(i);
		}
	}
}
void dfs(int x){
	vis[x]=1;
	par[x]=c;
	f(i,0,g[x].size())
		if(!vis[g[x][i]])
			dfs(g[x][i]);
}
 
int main(){
	pre();
	cin>>n>>q;
	f(i,0,n)
		cin>>a[i];
	f(i,0,n){
	   mark[d[a[i]][0]]=1;
		f(j,1,d[a[i]].size()){
			int u=d[a[i]][j-1],v=d[a[i]][j];
			g[u].pb(v);
			g[v].pb(u);
			mark[u]=mark[v]=1;
		}
	}
	f(i,2,N){
		if(mark[i] && !vis[i]){
			dfs(i),c++;
		}
	}
	f(i,0,n){
		int x=a[i]+1;
		d[x].pb(d[x-1][0]);
		f(j,0,d[x].size())
			f(k,0,j)
				if(par[d[x][j]]!=par[d[x][k]]){
					v.pb(mp(par[d[x][j]],par[d[x][k]]));
					v.pb(mp(par[d[x][k]],par[d[x][j]]));
				}
		d[x].pop_back();
	}
	v.pb(mp(N,N));
	sort(v.begin(),v.end());
	f(i,0,q){
		int u,x;
		Gett(u,x);
		u=a[u-1],x=a[x-1];
		u=par[d[u][0]],x=par[d[x][0]];
		if(u==x) cout<<0<<'\n';
		else{
			if(*lower_bound(v.begin(),v.end(),mp(u,x))==mp(u,x)) cout<<1<<'\n';
			else cout<<2<<'\n';
		}
	}
}