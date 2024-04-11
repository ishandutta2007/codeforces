#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+9;

int n,t,m,a,b,c,x,y,dist[3][N];
ll ans,p[N];
vector<int> g[N];

void bfs(int v,int src){
	queue<int> q;
	q.push(v);
	dist[src][v]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		f(i,0,g[u].size()){
			if(dist[src][g[u][i]]==-1){
				dist[src][g[u][i]]=dist[src][u]+1;
				q.push(g[u][i]);
			}
		}
	}
}
ll solve(int x){
	ll s;
	s=dist[0][x]+dist[1][x]+dist[2][x];
	if(s>m) return 1e18;
	return p[s]+p[dist[1][x]];
}

int main(){
	cin>>t;
	while(t--){
		ans=1e18;
		f(i,1,n+1) g[i].clear();
		cin>>n>>m>>a>>b>>c;
		
		fill(dist[0],dist[0]+n+2,-1);
		fill(dist[1],dist[1]+n+2,-1);
		fill(dist[2],dist[2]+n+2,-1);
		
		f(i,1,m+1){ get(p[i]); }
		sort(p+1,p+1+m);
		f(i,1,m+1) p[i]+=p[i-1];
		f(i,0,m){
			Gett(x,y);
			g[x].pb(y);
			g[y].pb(x);
		}
		bfs(a,0);
		bfs(b,1);
		bfs(c,2);
		f(i,1,n+1)
			minm(ans,solve(i));
		cout<<ans<<endl;
		
	}
}