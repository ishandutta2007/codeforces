#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
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

const int N=1e6+99;

int n,t,m,ck,a[N],col[N],d[2],mark[N];
vector<pair<int,int> > g[N];

void dfs(int x){
	mark[x]=1;
	d[col[x]]++;
	f(i,0,g[x].size()){
		if(!mark[g[x][i].F]){
			col[g[x][i].F]=col[x]^g[x][i].S;
			dfs(g[x][i].F);
		}
		if(col[g[x][i].F]!=(col[x]^g[x][i].S)) ck=1;
	}	
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int ans=0;
		ck=0;
		cin>>n>>m;
		f(i,1,n+1) g[i].clear(),mark[i]=0;
		f(i,0,m){
			int u,v;
			string s;
			cin>>u>>v>>s;
			g[u].pb(mp(v,(s[0]=='i')));
			g[v].pb(mp(u,(s[0]=='i')));
		}
		f(i,1,n+1){
			d[0]=d[1]=0;
			if(!mark[i]){
				col[i]=0;
				dfs(i);
			}
			ans+=max(d[0],d[1]);
		}
		if(ck) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}