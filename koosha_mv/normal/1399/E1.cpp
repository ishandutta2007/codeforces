#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,u,v,w,sub[N],ep[N];
ll S,sum;
vector<pair<int,int> > g[N];
set<pair<ll,int> > s;

void dfs(int x,int par,int c){
	sub[x]=(g[x].size()==1);
	f(i,0,g[x].size())
		if(g[x][i].F!=par)
			dfs(g[x][i].F,x,g[x][i].S),sub[x]+=sub[g[x][i].F];
	sum+=1ll*sub[x]*c;
	if(c)
		s.insert(mp(1ll*sub[x]*((c+1)/2),x)),ep[x]=c;
}
void change(int x){
	ep[x]/=2;
	s.insert(mp(1ll*sub[x]*((ep[x]+1)/2),x));
}
void solve(){
	int ans;
	for(ans=0;S<sum;ans++){
		pair<ll,int> p=*s.rbegin();
		s.erase(p);
		sum-=p.F;
		change(p.S);
	}
	cout<<ans<<'\n';
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>S;
		f(i,1,n+1) g[i].clear();
		s.clear(),sum=0;
		f(i,1,n){
			Gett(u,v);
			gett(w);
			g[u].pb(mp(v,w));
			g[v].pb(mp(u,w));
		}
		dfs(1,0,0);
		solve();
	}
}