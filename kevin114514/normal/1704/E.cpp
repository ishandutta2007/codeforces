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
void die(string S){puts(S.c_str());exit(0);}
int indeg[1010];
vector<int> G[1010];
bool f[1010][1010];
ll dp[1010][1010];
const ll mod=998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
				dp[i][j]=f[i][j]=0;
			G[i].clear();
			indeg[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>dp[i][0];
			if(dp[i][0])
				f[i][0]=1;
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].pb(v);
			indeg[v]++;
		}
		queue<int> q;
		for(int i=1;i<=n;i++)
			if(!indeg[i])
				q.push(i);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:G[u])
			{
				for(int i=0;i<n;i++) if(f[u][i])
				{
					dp[v][i+1]+=dp[u][i];
					while(dp[v][i+1]>=mod+mod)
						dp[v][i+1]-=mod;
					f[v][i+1]=1;
				}
				indeg[v]--;
				if(!indeg[v])
					q.push(v);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) if(!sz(G[i]))
		{
			ll sum=0;
			for(int j=0;j<=n;j++)
			{
				sum+=dp[i][j];
				if(f[i][j])
					ans=max(ans,sum+j);
				sum--;
				sum=max(sum,0ll);
			}
		}
//		cout<<ans<<endl;
		cout<<ans%mod<<endl;
	}
	return 0;
}