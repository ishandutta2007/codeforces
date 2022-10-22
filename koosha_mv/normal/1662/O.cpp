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

const int N=365*24;


int n,t,ans,a[N],b[N],vis[N];
vector<int> g[N];

void addedge(int u,int v){
	g[u].pb(v);
	g[v].pb(u);
}
void dfs(int u){
	vis[u]=1;
	if(u>=360*20) ans=1;
	for(auto v : g[u]){
		if(vis[v]==0) dfs(v);
	}
}
void Main(){
	fill(vis,vis+N,0);
	fill(a,a+N,1);
	fill(b,b+N,1);
	ans=0;
	cin>>n;
	f(i,0,n){
		char c;
		int deg,peg,r1,r2;
		cin>>c;
		if(c=='S'){
			cin>>r1>>r2>>deg;
			f(i,r1,r2){
				a[i*360+(deg+360-1)%360]=0;
			}
		}
		else{
			cin>>r1>>deg>>peg;
			for(int i=deg;i!=peg;i=(i+1)%360){
				b[(r1-1)*360+i]=0;
			}
		}
	}
	f(i,0,N-500){
		if(a[i]) addedge(i,(i%360==359 ? i-359 : i+1));
		if(b[i]) addedge(i,i+360);
	}
	dfs(0);
	cout<<(ans==1 ? "YES" : "NO")<<endl;
	f(i,0,N) g[i].clear();
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
6
C 1 180 90
C 5 250 230
C 10 150 140
C 20 185 180
S 1 20 180
S 5 10 0

1
5
C 1 180 90
C 5 250 230
C 10 150 140
C 20 185 180
S 1 20 180
*/