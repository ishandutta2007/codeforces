#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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

const int N=1e5+99;

int n,cent,pert,sz[N],root[N],dist[N],X[N],Y[N],mark[N],dp[N],pd[N];
vector<pair<int,int> > res,ans;
vector<int> g[N],v[N],mv[N];
ll k;

bool cmp(int i,int j){
	return (sz[root[i]]&1)>(sz[root[j]]&1);
}
void dfs1(int u,int p){
	sz[u]=1;
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
	if(cent==0 && sz[u]*2>=n){
		cent=u;
	}
}
void dfs2(int u,int p,int d,int rt){
	vector<int> vec;
	k-=d;
	dist[u]=d;
	for(auto v : g[u]){
		if(v==p) continue ;
		if(sz[v]&1) vec.pb(v);
	}
	
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs2(v,u,d+1,rt==0 ? v : rt);
	}
	
	if((sz[u]&1)==0) vec.pb(u);
	for(int i=0;i<vec.size() && cent!=u;i+=2){
		X[pert]=vec[i];
		Y[pert]=vec[i+1];
		root[pert]=rt;
		mv[rt].pb(pert);
		pert++;
	}
}
void dfs3(int u,int p,int d){
	vector<int> vec;
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs3(v,u,d+1);
		pd[u]|=pd[v];
		if(dp[v]){
			vec.pb(dp[v]);
		}
	}
	if(!mark[u]){
		dp[u]=u;
		vec.pb(u);
	}
	if(vec.size()>1 && d==k && k>0 && pd[u]){
		k=0;
		mark[vec[0]]=mark[vec[1]]=1;
		ans.pb({vec[0],vec[1]});
	}
}
void dfs4(int u,int p,int rt){
	if(rt==0 && cent!=u) rt=u;
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs4(v,u,rt);
	}
	if(!mark[u]){
		res.pb({rt,u});
	}
}
void solve(){
	dfs3(cent,0,0);
	dfs4(cent,0,0);
	sort(all(res));
	f(i,0,res.size()/2){
		ans.pb({res[i].S,res[i+res.size()/2].S});
	}
	if(k>0){ cout<<"NO"; return ; }
	cout<<"YES"<<endl;
	for(auto x : ans){
		cout<<x.F<<" "<<x.S<<endl;
	}
}

int main(){
	cin>>n>>k;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,0);
	dfs1(cent,0);
	dfs2(cent,0,0,0);
	
	k=-k;
	if(k<0 || (k&1)) return cout<<"NO",0;
	k/=2;
	
	f(i,1,n+1){
		f_(j,mv[i].size()-1,0){
			v[mv[i].size()-j].pb(mv[i][j]);
		}
	}
	f_(i,n,1){
		bool b=0;
		sort(all(v[i]),cmp);
		for(auto id : v[i]){
			if(max(dist[X[id]],dist[Y[id]])-1<=k){
				ans.pb({X[id],Y[id]});
				mark[X[id]]=mark[Y[id]]=1;
				k-=max(dist[X[id]],dist[Y[id]])-1;
			}
			else{
				b=1;
				pd[X[id]]=1;
				pd[Y[id]]=1;
				break; 
			}
		}
		if(b) break;
	}
	solve();
}