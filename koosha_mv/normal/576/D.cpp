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

const int N=200,lg=32,inf=1e9+N;

int n,m,ans=inf,a[N],b[N],Dist[N],dist[lg][N][N];
vector<int> vd;
vector<pair<int,int> > g[N];

void Apply(int x,int k){
	f(l,0,lg){
		if(x&(1<<l)){
			fill(b,b+N,0);
			f(u,1,n+1){
				f(v,1,n+1){
					if(a[u] && dist[l][u][v]<k){
						b[v]=1;
					}
				}
			}
			f(i,0,N) a[i]=b[i];
		}
	}	
	//cout<<"A : "; f(i,1,n+1) cout<<a[i]<<" "; cout<<endl;
}
void bfs(int x){
	fill(Dist,Dist+N,inf);
	queue<int> q;
	f(i,1,n+1) if(a[i]) q.push(i),Dist[i]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		f(i,0,g[u].size()){
			if(g[u][i].S<=x && Dist[u]+1<Dist[g[u][i].F]){
				q.push(g[u][i].F);
				Dist[g[u][i].F]=Dist[u]+1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	f(i,0,lg) f(j,0,N) f(k,0,N) dist[i][j][k]=inf;
	cin>>n>>m;
	f(i,0,m){
		int u,v,d;
		cin>>u>>v>>d;
		g[u].pb(mp(v,d));
		minm(dist[0][u][v],d);
		vd.pb(d);
	}
	sort(vd.begin(),vd.end());
	f(l,1,lg){
		f(u,1,n+1){
			f(v,1,n+1){
				f(k,1,n+1){
					minm(dist[l][u][v],max(dist[l-1][u][k],dist[l-1][k][v]));
				}
			}
		}
	}
	int last=0;
	a[1]=1;
	f(i,0,vd.size()){
		Apply(vd[i]-last,vd[i]);
		last=vd[i];
		bfs(vd[i]);
		minm(ans,vd[i]+Dist[n]);
	}
	if(ans>=inf) cout<<"Impossible";
	else cout<<ans;
}
/*
3 4
2 1 0
3 3 1
1 2 0
1 3 3
*/