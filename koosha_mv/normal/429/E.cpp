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

int n,t,cnt,a[N],X[N],Y[N],ans[N];
vector<pair<int,int> > g[N];
vector<int> vec;

int find(int x){
	return lower_bound(vec.begin(),vec.end(),x)-vec.begin();
}
void Add_edge(int u,int v){
	//cout<<u<<" -> "<<v<<endl;
	g[u].pb(mp(v,cnt));
	g[v].pb(mp(u,cnt+1));
	cnt+=2;
}
void dfs(int x){
	while(g[x].size() && ans[g[x].back().S/2]!=-1) g[x].pop_back();
	if(g[x].size()){
		pair<int,int> p=g[x].back();
		g[x].pop_back();
		ans[p.S/2]=(p.S&1);
		dfs(p.F);
	}
}
int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(ans,ans+N,-1);
	cin>>n;
	f(i,0,n){
		cin>>X[i]>>Y[i];
		Y[i]++;
		vec.pb(X[i]);
		vec.pb(Y[i]);
	}
	
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	
	f(i,0,n){
		int u=find(X[i]),v=find(Y[i]);
		Add_edge(u,v);
	}
	
	int last=-1;
	f(i,0,vec.size()){
		if(sz(g[i])&1){
			if(last==-1) last=i;
			else{
				Add_edge(last,i);
				last=-1;
			}
		}
	}
	f(i,0,vec.size()){
		dfs(i);
	}	
	f(i,0,n){
		cout<<ans[i]<<" ";
	}
}