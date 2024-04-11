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

const int N=1010,mod=998244353,inf=1e8;

int n,m,t,ans,a[N],vis[N],res[N],dp[N][N],r1[N],d1[N][N];
vector<int> g[N];

void dfs(int u){
	vis[u]=1;
	f(i,0,n+1) dp[u][i]=d1[u][i]=0;
	if(g[u].size()==0){
		dp[u][0]=d1[u][0]=1;
	}
	for(auto v : g[u]){
		if(vis[v]==0){
			dfs(v);
		}
		f(i,1,n+1){
			Add(dp[u][i],dp[v][i-1]);
			d1[u][i]=min(inf,d1[u][i]+d1[v][i-1]);
		}
	}
	f(i,0,n+1){
		Add(res[i],1ll*a[u]*dp[u][i]%mod);
		r1[i]=min(inf,r1[i]+1ll*a[u]*d1[u][i]);
	}
}
void Main(){
	cin>>n>>m;
	f(i,1,n+1) cin>>a[i];
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
	}
	f(i,1,n+1){
		if(!vis[i]){
			dfs(i);
		}
	}
	int sum=0;
	f_(i,n,0){
		Add(sum,res[i]);
	}
	int mx=0;
	ans=sum;
	sum=0;
	int mv=0;
	f(i,0,n) if(r1[i]) mv=i;
	f(i,0,mv){
		sum+=1;
		sum-=r1[i];
		maxm(mx,sum);
	}
	cout<<(ans+mx)%mod<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		ans=0;
		f(i,0,n+1) vis[i]=res[i]=r1[i]=0,g[i].clear();
	}
}
/*
1
6 9
10 10 10 10 10 10
1 2
1 3
2 3
4 3
6 3
3 5
6 5
6 1
6 2

*/