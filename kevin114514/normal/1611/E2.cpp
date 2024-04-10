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
void die(string S){puts(S.c_str());exit(0);}
int dist[200200],me[200200];
vector<int> G[200200];
bool used[200200];
int dfs(int u,int fa)
{
//	cout<<u<<" "<<fa<<" "<<used[u]<<" "<<me[u]<<" "<<dist[u]<<endl;
	if(me[u]>=dist[u])
		return 1;
	int sum=0;
	for(auto v:G[u])
		if(v!=fa)
			sum+=dfs(v,u);
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			used[i]=0;
		for(int i=1;i<=n;i++)
		{
			dist[i]=me[i]=-1;
			G[i].clear();
		}
		queue<int> q;
		for(int i=0;i<k;i++)
		{
			int x;
			cin>>x;
			q.push(x);
			used[x]=1;
			dist[x]=0;
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			G[x].pb(y);
			G[y].pb(x);
		}
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:G[u]) if(dist[v]==-1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
		q.push(1);
		me[1]=0;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:G[u]) if(me[v]==-1)
			{
				me[v]=me[u]+1;
				q.push(v);
			}
		}
		bool fl=0;
		for(int i=2;i<=n;i++)
			if(sz(G[i])==1&&me[i]<dist[i])
				fl=1;
		if(fl)
			puts("-1");
		else	cout<<dfs(1,0)<<endl;
	}
	return 0;
}