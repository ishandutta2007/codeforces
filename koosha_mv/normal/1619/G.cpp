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

const int N=1e6+99;

int n,T,k,mv,Max,a[N],X[N],Y[N],t[N],vis[N];
vector<int> g[N];

bool cmp1(int i,int j){
	return mp(X[i],Y[i])<mp(X[j],Y[j]);
}
bool cmp2(int i,int j){
	return mp(Y[i],X[i])<mp(Y[j],X[j]);	
}
void Add_edge(int u,int v){
	g[u].pb(v);
	g[v].pb(u);
}
void dfs(int u){
	vis[u]=1;
	if(t[u]<=Max) mv=0;
	for(auto v : g[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}
bool check(int x){
	fill(vis,vis+n,0);
	int res=0;
	f(i,0,n){
		if(!vis[i]){
			mv=1;
			Max=x;
			dfs(i);
			res+=mv;
		}
	}
	return res<=x+1;
}
void Main(){
	cin>>n>>k;
	vector<int> v(n);
	iota(all(v),0);
	f(i,0,n){
		cin>>X[i]>>Y[i]>>t[i];
	}
	sort(all(v),cmp1);
	f(i,0,v.size()){
		if(i>0 && X[v[i-1]]==X[v[i]] && Y[v[i]]-Y[v[i-1]]<=k){
			Add_edge(v[i-1],v[i]);
		}
	}
	sort(all(v),cmp2);
	f(i,0,v.size()){
		if(i>0 && Y[v[i-1]]==Y[v[i]] && X[v[i]]-X[v[i-1]]<=k){
			Add_edge(v[i-1],v[i]);
		}
	}
	int l=-1,r=1e9;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<'\n';
	f(i,0,n) g[i].clear();
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		Main();
	}	
}