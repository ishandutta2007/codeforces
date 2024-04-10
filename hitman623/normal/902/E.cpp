#include <bits/stdc++.h>
#define	int 		long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
vi ad[300005];
int v[300005],ans[300005],s[300005],p[300005];
map<pii,int> vv;
stack<int> path;
void dfs(int node,int par)
{
	vv[{node,par}]=1;
	vv[{par,node}]=1;
	if(v[node])
	{
		vi temp;
		int g=node,gg=node;
		while(!path.empty() && path.top()!=node){
			temp.pb(path.top());
			g=max(g,path.top());
			gg=min(gg,path.top());
			path.pop();
		}
		temp.pb(node);
		ans[gg]=min(ans[gg],g-1);
		return;
	}
	v[node]=1;
	path.push(node);
	for(auto i:ad[node])
		if(!vv[{i,node}])
			dfs(i,node);
	if(path.size())
	path.pop();
}
void solve()
{
	int n,m,q;
	cin>>n>>m;
	rep(i,1,n+1)
		ans[i]=n;
	rep(i,0,m){
		int a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	rep(i,1,n+1)
		if(!v[i]){
			dfs(i,-1);
		}
	for(int i=n-1;i>=1;i--)
		ans[i]=min(ans[i],ans[i+1]);
	rep(i,1,n+1){
		s[i]=s[i-1]+ans[i];
	}
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int g=lower_bound(ans+l,ans+r+1,r)-ans;
		cout<<s[g-1]-s[l-1]+(r-g+1)*r-r*(r+1)/2+l*(l-1)/2+r-l+1<<endl;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
	return 0;
}