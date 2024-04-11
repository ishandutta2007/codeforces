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

const int N=1e6+99;

int n,t,a[N],res[N],deg[N],mark[N];
vector<int> g[N];

void Main(){
	cin>>n;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int b=0;
	f(i,1,n+1){
		mark[i]=0;
		deg[i]=g[i].size();
		if(g[i].size()>2) b=1;
	}
	if(b==0){
		cout<<min(1ll,n-1)<<'\n';
		return ;
	}
	queue<int> q;
	f(i,1,n+1){
		if(g[i].size()==1){
			q.push(i);
			mark[i]=1;
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v : g[u]){
			res[v]++;
			deg[v]--;
			if(deg[v]==1  && g[v].size()==2){
				q.push(v);
				mark[v]=1;
			}
		}
	}
	int ans=0;
	f(i,1,n+1){
		if(mark[i]) continue ;
		ans+=max(0ll,res[i]-1);
	}
	cout<<ans<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,1,n+1) res[i]=deg[i]=mark[i]=0,g[i].clear();
	}
}