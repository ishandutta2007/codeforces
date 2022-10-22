#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
#define get(x) scanf("%I64d",&x)
#define gett(x) scanf("%d",&x)
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

const int N=3e5+99,mod=998244353;

int n,t,m,k,mv,sz,a[N],cnt[N],mark[N],deg[N],lt[N];
int dp[N];
vector<int> g[N];
vector<int> V;

void Add_edge(int u,int v,int i){
	if(lt[v]!=u) lt[v]=u,deg[v]++;
	g[u].pb(v);
}
void dfs(int x){
	int adj=0;
	sz++;
	mark[x]=1;
	sort(g[x].begin(),g[x].end());
	f(i,0,g[x].size()){
		if(i==0 || g[x][i]!=g[x][i-1]){
			adj++;
			if(!mark[g[x][i]]){
				dfs(g[x][i]);
			}
			else
				mv=0;
		}
	}
	if(adj>1 || deg[x]>1) mv=0;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	f(i,0,n){
		int c,x=0,mv=0;
		cin>>c;
		f(j,0,c){
			int last=x;
			cin>>x;
			if(last){
				Add_edge(x,last,i);
			}
		}
	}
	f(i,1,k+1){
		if(!mark[i] && deg[i]==0){
			sz=0;
			mv=1;
			dfs(i);
			if(mv){
				cnt[sz]++;
			}
		}
	}
	dp[0]=1;
	f(i,1,N){
		if(cnt[i])
			V.pb(i);
	}
	f(i,0,N){
		f(j,0,V.size()){
			int x=V[j];
			if(i+x<N){
				Add(dp[i+x],1ll*dp[i]*cnt[x]%mod);
			}
		}
	}
	cout<<dp[m];
}