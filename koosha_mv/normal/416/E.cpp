#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=505,inf=1e9;

int n,t,m,a[N],mark[N],deg[N][N],dist[N][N],ans[N][N];
vector<pair<int,int> > g[N];

void bfs(int s){
	f(i,0,N) dist[s][i]=inf;
	fill(mark,mark+N,0);
	dist[s][s]=0;
	f(T,0,n){
		int u=-1;
		f(i,1,n+1){
			if(!mark[i] && (u==-1 || dist[s][i]<dist[s][u])){
				u=i;
			}
		}
		mark[u]=1;
		f(i,0,g[u].size()){
			minm(dist[s][g[u][i].F],dist[s][u]+g[u][i].S);
		}
	}
	f(i,1,n+1){
		for(auto u : g[i]){
			if(u.S+dist[s][u.F]==dist[s][i]){
				deg[s][i]++;
			}
		}
	}
	
}
int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,0,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	}
	f(i,1,n+1){
		bfs(i);
	}
	f(i,1,n+1){
		f(j,1,n+1){
			f(k,1,n+1){
				if(dist[i][j]+dist[j][k]==dist[i][k]){
					ans[i][k]+=deg[k][j];
				}
			}
		}
	}
	f(i,1,n+1){
		f(j,i+1,n+1){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}