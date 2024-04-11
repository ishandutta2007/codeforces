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

const int N=1e5+99,sq=340,lg=20;

int n,m,cnt,type[N],s[N],t[N],v[N],a[N],h[N],par[lg][N],dist[N];
vector<int> g[N];

bool is_par(int u,int v){
	return s[u]<=s[v] && s[v]<=t[u];
}
int Lca(int u,int v){
	if(is_par(u,v)) return u;
	f_(i,lg-1,0){
		if(!is_par(par[i][u],v)){
			u=par[i][u];
		}
	}
	return par[0][u];
}
int Get_dist(int u,int v){
	int lca=Lca(u,v);
	return h[u]+h[v]-2*h[lca];
}
void dfs(int x){
	s[x]=cnt++;
	f(i,1,lg) par[i][x]=par[i-1][par[i-1][x]];	
	f(i,0,g[x].size()){
		if(g[x][i]!=par[0][x]){
			par[0][g[x][i]]=x;
			h[g[x][i]]=h[x]+1;
			dfs(g[x][i]);
		}
	}
	t[x]=cnt++;
}
void bfs(int x){
	fill(dist,dist+N,N);
	queue<int> q;
	q.push(1);
	dist[1]=0;
	f(i,0,x){
		if(type[i]==1){
			dist[v[i]]=0;
			q.push(v[i]);
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		f(i,0,g[u].size()){
			if(dist[u]+1<dist[g[u][i]]){
				q.push(g[u][i]);
				dist[g[u][i]]=dist[u]+1;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	par[0][1]=1;
	dfs(1);
	f(i,0,m){
		cin>>type[i]>>v[i];
	}
	for(int i=0;i<m;i+=sq){
		bfs(i);
		for(int j=i;j<i+sq && j<m;j++){
			if(type[j]==2){
				int u=v[j],ans=dist[u];
				f(k,i,j){
					if(type[k]==1){
						minm(ans,Get_dist(u,v[k]));
					}
				}
				cout<<ans<<endl;
			}
		}
	}
}