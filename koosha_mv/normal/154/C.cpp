#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y,s) x=(x+y)%mod[s];
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,base=37,mod[2]={1000000009,1000000007},S=2;

int n,m,a[N],Pow[S][N],adj[S][N];
map<pair<int,int> ,int> mark;
ll ans;

void solve(){
	mark.clear();
	f(i,1,n+1){
		ans+=mark[mp(adj[0][i],adj[1][i])]++;		
	}	
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Pow[0][0]=Pow[1][0]=1;
	f(s,0,S) f(i,1,N) Pow[s][i]=998244353ll*Pow[s][i-1]%mod[s];
	cin>>n>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		f(s,0,2){
			Add(adj[s][u],Pow[s][v],s);
			Add(adj[s][v],Pow[s][u],s);
		}
	}
	solve();
	f(s,0,S) f(i,1,n+1) Add(adj[s][i],Pow[s][i],s);
	solve();
	cout<<ans;
}