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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int b[100100];
int mn[100100],mx[100100];
vector<int> G[100100];
int indeg[100100];
vector<int> vec;
bool vis[100100];
//void dfs(int u)
//{
//	vis[u]=1;
//	vec.pb(u);
//	for(auto v:G[u]) if(!vis[v])
//		dfs(v);
//}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>b[i];
		mn[0]=inf;
		mx[n+1]=0;
		for(int i=1;i<=n;i++)
			mn[i]=min(mn[i-1],b[i]);
		for(int i=n;i>=1;i--)
			mx[i]=max(mx[i+1],b[i]);
		int k=0;
		for(int i=1;i<=n;i++)
			if(mn[i]>i&&mx[i+1]<=i)
			{
				k=i;
				break;
			}
		for(int i=0;i<=n+1;i++)
			G[i].clear(),indeg[i]=0;
		for(int i=1;i<=k;i++)
//			if(b[i]<=n)
			{
				G[b[i]].pb(i);
				indeg[b[i]]++;
			}
		for(int i=k+1;i<=n;i++)
//			if(b[i])
			{
				G[b[i]].pb(i);
				indeg[b[i]]++;
			}
		vec.clear();
		for(int i=n;i>=1;i--)
			vis[i]=0;
		queue<int> qu;
		qu.push(0);
		qu.push(n+1);
		while(!qu.empty())
		{
			int u=qu.front();
			qu.pop();
			sort(ALL(G[u]),[&](int a,int b){return sz(G[a])<sz(G[b]);});
			for(auto v:G[u]) if(!vis[v])
			{
				vis[v]=1;
				qu.push(v);
				vec.pb(v);
			}
		}
		assert(sz(vec)==n);
		cout<<k<<'\n';
		for(auto x:vec)
			cout<<x<<" ";
		cout<<'\n';
	}
	return 0;
}