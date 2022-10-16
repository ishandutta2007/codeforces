#include<bits/stdc++.h>
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
void die(string S){puts(S.c_str());exit(0);}
int dp[5050][5050];
int fm[5050][5050];
vector<pair<int,int> > G[5050];
vector<int> Topo;
int indeg[5050];
void TopoSort(int n)
{
	queue<int> Seq;
	for(int i=1;i<=n;i++)
		if(!indeg[i])
		{
			Seq.push(i);
			Topo.pb(i);
		}
	while(!Seq.empty())
	{
		int x=Seq.front();
		Seq.pop();
		for(int i=0;i<sz(G[x]);i++)
		{
			indeg[G[x][i].first]--;
			if(!indeg[G[x][i].first])
			{
				Seq.push(G[x][i].first);
				Topo.pb(G[x][i].first);
			}
		}
	}
}
int main()
{
	int n,m;
	ll t;
	cin>>n>>m>>t;
	t++;
	for(int i=0;i<5050;i++)
		for(int j=0;j<5050;j++)
			dp[i][j]=t;
	while(m--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		G[x].pb(mp(y,z));
		indeg[y]++;
	}
	TopoSort(n);
	dp[1][1]=0;
	fm[1][1]=-1;
	for(int i=0;i<n;i++)
	{
		int x=Topo[i];
		for(int j=1;j<=n;j++)
			for(int ind=0;ind<sz(G[x]);ind++)
			{
				int to=G[x][ind].first;
				if(dp[x][j]+G[x][ind].second<dp[to][j+1])
				{
					dp[to][j+1]=dp[x][j]+G[x][ind].second;
					fm[to][j+1]=x;
				}
			}
	}
	int ans=-1;
	for(int j=n;j>=0;j--)
		if(dp[n][j]!=t)
		{
			ans=j;
			break;
		}
	cout<<ans<<endl;
	vector<int> res;
	int x=n;
	for(int j=ans;j>=1;j--)
	{
		res.pb(x);
		x=fm[x][j];
	}
	rev(res);
	for(int i=0;i<ans;i++)
		cout<<res[i]<<" ";
	return 0;
}