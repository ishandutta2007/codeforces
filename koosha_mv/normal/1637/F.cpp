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
#define int ll

const int N=2e5+99;

int n,rt,mv,now,cnt,a[N],dp[N],st[N],ts[N],ft[N];
ll ans;
vector<int> g[N];
vector<pair<int,int> > v;
set<int> s;

void dfs1(int u,int p){
	int b=0;
	f(i,0,3) if(u==v[i].S){
		b=1;
		dp[u]=1;
	}
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs1(v,u);
		dp[u]+=dp[v];
	}
	if(p==0) return ;
	if(dp[u]>1 && b==0){
		mv=1;
	}
	minm(dp[u],1ll);
	//cout<<u<<" -> "<<dp[u]<<endl;
}
void dfs2(int u,int p){
	int b=0;
	dp[u]=0;
	ts[cnt]=u;
	st[u]=cnt++;
	f(i,0,3) if(u==v[i].S){
		dp[u]=1;
		b=1;
	}
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs2(v,u);
		dp[u]+=dp[v];
	}
	ft[u]=cnt;
	if(b==1 && dp[u]==1){
		s.insert(st[u]);
	}
}
void findrt(){
	dfs1(v[0].S,0);	
	//eror(v[0].S);
	//eror(dp[v[0].S]);
	if(mv==1){
		ans+=v[2].F;
	}
	//eror(ans);
	if(dp[v[0].S]>2){
		rt=v[0].S;
	}
	else{
		for(auto x : g[v[0].S]){
			if(dp[x]){
				rt=x;
				break;
			}
		}
	}
	dfs2(rt,0);
	for(auto x : s){
	//	cout<<ts[x]<<" : "<<x<<endl;
	}
}
void add(int u){
	if(s.lower_bound(st[u])!=s.end() && *s.lower_bound(st[u])<ft[u]){
		return ;
	}
	if(*s.begin()<st[u] && st[u]<ft[ts[*prev(s.lower_bound(st[u]))]]){
		s.erase(*prev(s.lower_bound(st[u])));
	}
	s.insert(st[u]);
}
	
main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		v.pb({a[i],i});
	}	
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	sort(all(v),greater<pair<int,int>> ());
	if(n==2){
		cout<<2ll*v[0].F;
		exit(0);
	}
	ans+=2*v[0].F;
	
	findrt();
	f(i,3,n){
		int last=s.size();
		add(v[i].S);
		ans+=v[i].F*(s.size()-last);
	}
	cout<<ans;
}
/*
4
80 20 40 10
1 2
1 3
1 4
*/