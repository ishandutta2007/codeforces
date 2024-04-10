#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(time(0));
const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int mn=2e5+10;
ll hv[mn];
int fib[mn];
set<int>g[mn];
int s[mn],hsh[mn],par[mn];
int pp[mn];
vector<int>hmm;
void dfs(int x,int p,int n){
	s[x]=1;
	par[x]=p;
	hsh[x]=hv[x];
	for(int y:g[x])if(y!=p){
		dfs(y,x,n);
		s[x]+=s[y];
		hsh[x]^=hsh[y];
	}
	if(s[x]==fib[n-1]||s[x]==fib[n-2])hmm.push_back(x);
}
map<ll,bool> dp;
bool solve(int n,int x){
	if(n<=3)return 1;
	hmm.clear();
	dfs(x,x,n);
	//cerr<<x<<" "<<s[x]<<" "<<fib[n]<<endl;
	assert(s[x]==fib[n]);
	ll hx=hsh[x];
	if(dp.find(hx)!=dp.end())return dp[hx];
	vector<int> v= hmm,pv,sv;
	for(int y:v)pv.push_back(par[y]),sv.push_back(s[y]);
	for(int i=0;i<v.size();i++){
		int y=v[i],py=pv[i],sy=sv[i];
		g[y].erase(py);
		g[py].erase(y);
		bool ans;
		if(sy==fib[n-1])ans=(solve(n-1,y)&&solve(n-2,py));
		else ans=(solve(n-2,y)&&solve(n-1,py));
		g[y].insert(py);
		g[py].insert(y);
		if(ans)return dp[hx]=1;
	}
	return dp[hx]=0;
}

signed main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	fib[0]=fib[1]=1;
	for(int i=1;fib[i]<=n;i++)fib[i+1]=fib[i]+fib[i-1];
	for(int i=1;i<=n;i++)hv[i]=rng();
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].insert(b);
		g[b].insert(a);
	}
	int st=-1;
	for(int i=0;fib[i]<=n;i++)if(fib[i]==n)st=i;
	if(st<0)printf("NO\n");
	else printf("%s\n",solve(st,1)?"YES":"NO");
}