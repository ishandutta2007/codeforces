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

const int N=1e6+99,lg=20;

int n,t,a[N],h[N],d[2],ans[N],cnt[N],mark[N];
vector<int> v[2],g[N];

void dfs(int x,int par){
	d[h[x]]++;
	v[h[x]].pb(x);
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			h[g[x][i]]=h[x]^1;
			dfs(g[x][i],x);
		}
	}
}
int fb(int mask){
	f_(i,lg-1,0){
		if(mask&(1<<i)){
			return i;
		}
	}
}
void Main(){
	fill(cnt,cnt+lg,0);
	d[0]=d[1]=0;
	v[0].clear();
	v[1].clear();
	cin>>n;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1){
		cnt[fb(i)]++;
	}
	dfs(1,0);
	f_(i,lg-1,0){
		if(cnt[i]<=d[0]){
			mark[i]=0;
			d[0]-=cnt[i];
		}
		else{
			mark[i]=1;
		}
	}
	f(i,1,n+1){
		if(mark[fb(i)]==0){
			ans[v[0].back()]=i;
			v[0].pop_back();
		}
		else{
			ans[v[1].back()]=i;
			v[1].pop_back();
		}
	}
	f(i,1,n+1){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	f(i,1,n+1) g[i].clear();
}

int main(){
	cin>>t;
	while(t--){
		Main();
	}
}