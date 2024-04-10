#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[300300];
int depth[300300];
int a[300300],b[300300];
int f[300300];
void dfs(int u,int fa)
{
//	cout<<u<<" "<<fa<<endl;
	depth[u]=depth[fa]+1;
	a[u]=b[u]=depth[u];
	for(auto v:G[u]) if(v!=fa)
	{
		dfs(v,u);
		if(a[v]>a[u])
		{
			b[u]=a[u];
			a[u]=a[v];
		}
		else if(a[v]>b[u])
			b[u]=a[v];
	}
//	cout<<u<<" "<<depth[u]<<" "<<a[u]<<" "<<b[u]<<endl;
	if(min(a[u],b[u]))
		f[min(a[u],b[u])-1]=max(f[b[u]-1],a[u]+b[u]-2*depth[u]+1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n;i++)
			f[i]=1,
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
		}
		depth[0]=-1;
		dfs(1,0);
		for(int i=n-2;i>=0;i--)
			f[i]=max(f[i+1],f[i]);
		int depthh=*max_element(depth+1,depth+n+1);
//		for(int i=0;i<=n;i++)
//			cout<<f[i]<<" ";
//		puts("");
		int ans=0;
		for(int x=1;x<=n;x++)
		{
			while(ans<depthh&&f[ans]/2+x>ans) ans++;
			cout<<ans<<" ";
		}
		puts("");
	}
	return 0;
}