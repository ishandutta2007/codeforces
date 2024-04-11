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

const int N=55,inf=N*N*N;

int n,m,s,ans=inf,cnt[N],a[N][N],dp[N][N][N][N];
vector<int> g[N];

void dfs1(int u,int p){
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs1(v,u);
		cnt[u]+=cnt[v];
	}
}
int calc(int u,int v,int cnt0,int cnt1){
	if(dp[u][v][cnt0][cnt1]!=-1) return dp[u][v][cnt0][cnt1];
	if(cnt0==0 && cnt1==0) return dp[u][v][cnt0][cnt1]=0;
	if(cnt0==0){
		return dp[u][v][cnt0][cnt1]=inf;
	}
	if(g[v].size()==1){
		return dp[u][v][cnt0][cnt1]=a[u][v]+calc(v,u,cnt1,0);
	}
	int l=0,r=inf;
	while(l+1<r){
		int mid=(l+r)>>1,sum=0;
		for(auto x : g[v]){
			if(x==u) continue ;
			int t=-1;
			f(j,0,cnt0+1){
				if(mid<=calc(v,x,j,cnt0+cnt1-j)){
					maxm(t,j);
				}
			}
			sum+=t;
			if(sum>=cnt0) break;
		}
		if(sum>=cnt0) l=mid;
		else r=mid;
	}
	return dp[u][v][cnt0][cnt1]=l+a[u][v];
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,0,N) f(j,0,N) f(k,0,N) f(p,0,N) dp[i][j][k][p]=-1;
	cin>>n;
	f(i,1,n){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb(v);
		g[v].pb(u);
		a[u][v]=a[v][u]=w;
	}
	cin>>s>>m;
	f(i,0,m){
		int x;
		cin>>x;
		cnt[x]++;
	}
	dfs1(s,s);
	for(auto v : g[s]){
		minm(ans,calc(s,v,cnt[v],m-cnt[v]));
	}
	cout<<ans;
}