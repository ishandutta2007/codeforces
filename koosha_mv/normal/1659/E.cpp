#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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
#define int ll

const int N=1e5+99,lg=30;

int n,m,q,cnt,a[N],vis[N],ok[N][lg],col[N][lg];
vector<pair<int,int>> g[N];

void dfs(int u,int l){
	vis[u]=1;
	col[u][l]=cnt;
	for(auto v : g[u]){
		if(bit(v.S,0)==0) ok[cnt][l]=1;
		if(vis[v.F]==0 && bit(v.S,l)) dfs(v.F,l);
	}
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,0,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}	
	f(l,0,lg){
		fill(vis,vis+N,0);
		cnt=0;
		f(i,1,n+1){
			if(vis[i]==1) continue ;
			cnt++;
			dfs(i,l);
		}
	}
	cin>>q;
	while(q--){
		int u,v,b=0;
		cin>>u>>v;
		f(i,0,lg) if(col[u][i]==col[v][i]){
			b=1;
			cout<<0<<'\n';
			break ;
		}
		if(b==1) continue ;
		f(i,1,lg) if(ok[col[u][i]][i]){
			//eror(i);
			b=1;
			cout<<1<<'\n';
			break;
		}
		if(b==1) continue ;
		cout<<2<<'\n';
	}
}
/*
6 7
1 2 1
2 3 3
3 1 5
4 5 2
5 6 4
6 4 6
3 4 1
1
1 5
*/