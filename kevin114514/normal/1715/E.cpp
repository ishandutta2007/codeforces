#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define int ll
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
ll dist[100100][22];
vector<pii> G[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m,k;
	cin>>n>>m>>k;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].pb(mp(v,w));
		G[v].pb(mp(u,w));
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dist[i][j]=1ll*inf*inf;
	dist[1][0]=0;
	for(int i=0;i<=k;i++)
	{
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		for(int j=1;j<=n;j++)
			pq.push(mp(dist[j][i],j));
		while(!pq.empty())
		{
			int d=pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(dist[u][i]!=d)
				continue;
			for(auto p:G[u])
			{
				int ndist=p.second+d;
				int v=p.first;
				if(ndist<dist[v][i])
				{
					dist[v][i]=ndist;
					pq.push(mp(ndist,v));
				}
			}
		}
		if(i<k)
		{
			for(int j=1;j<=n;j++)
				dist[j][i+1]=min(dist[j][i+1],dist[j][i]);
			deque<pii> q;
			for(int j=1;j<=n;j++)
			{
				while(sz(q)>=2&&(q[0].first-q[0].second*j)>(q[1].first-q[1].second*j)) q.pop_front();
				if(sz(q)>=1)
					dist[j][i+1]=min(dist[j][i+1],q[0].first-q[0].second*j+j*j);
				while(sz(q)>=2&&(q[sz(q)-1].first-q[sz(q)-2].first)*1.0/(q[sz(q)-1].second-q[sz(q)-2].second)>(dist[j][i]+j*j-q[sz(q)-2].first)*1.0/(j+j-q[sz(q)-2].second))
					q.pop_back();
				q.push_back(mp(dist[j][i]+j*j,j+j));
			}
			q.clear();
			for(int j=n;j>=1;j--)
			{
				while(sz(q)>=2&&(q[0].first-q[0].second*j)>(q[1].first-q[1].second*j)) q.pop_front();
				if(sz(q)>=1)
					dist[j][i+1]=min(dist[j][i+1],q[0].first-q[0].second*j+j*j);
				while(sz(q)>=2&&(q[sz(q)-1].first-q[sz(q)-2].first)*1.0/(q[sz(q)-1].second-q[sz(q)-2].second)<(dist[j][i]+j*j-q[sz(q)-2].first)*1.0/(j+j-q[sz(q)-2].second))
					q.pop_back();
				q.push_back(mp(dist[j][i]+j*j,j+j));
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dist[i][k]<<" ";
	return 0;
}