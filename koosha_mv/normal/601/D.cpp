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

const int N=3e5+99;

int n,ans,cnt,a[N],w[N],sz[N],Par[N];
map<pair<int,int> ,int> mark;
vector<int> g[N];
set<int> S[N];
string s;

void dfs1(int x){
	sz[x]=1;
   if(!mark[mp(w[Par[x]],s[x])]) mark[mp(w[Par[x]],s[x])]=++cnt;
   w[x]=mark[mp(w[Par[x]],s[x])];
   f(i,0,g[x].size()){
   	if(g[x][i]!=Par[x]){
   		Par[g[x][i]]=x;
   		dfs1(g[x][i]);
   		sz[x]+=sz[g[x][i]];
		}
	}
}
void dfs2(int x){
	int u=0;
	f(i,0,g[x].size()){
		if(g[x][i]!=Par[x]){
			dfs2(g[x][i]);
			if(sz[g[x][i]]>sz[u]) u=g[x][i];
		}
	}
	if(u>0) swap(S[u],S[x]);
	f(i,0,g[x].size()){
		if(g[x][i]!=u && g[x][i]!=Par[x]){
			for(auto  X : S[g[x][i]]){
				S[x].insert(X);
			}
		}
	}
	S[x].insert(w[x]);
	if(S[x].size()+a[x]>ans){
		ans=S[x].size()+a[x];
		cnt=0;
	}
	if(S[x].size()+a[x]==ans) cnt++;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	cin>>s;
	s=' '+s;
	f(i,1,n){
	   int u,v;
	   cin>>u>>v;
	   g[u].pb(v);
	   g[v].pb(u);
	}
	dfs1(1);
	dfs2(1);
	cout<<ans<<endl<<cnt<<endl;
}