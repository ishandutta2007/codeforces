//Author: Kevin5307
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
string s[600300];
vector<pii> G[600300];
ll dist[600300];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	for(int i=0;i<n;i++)
		cin>>s[i];
	auto f=[&](int x,int y){return x*m+y;};
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='R')
			{
				if(i<n-1)
					G[f(i+1,j-1)].pb(mp(f(i,j),p));
				if(i)
					G[f(i-1,j-1)].pb(mp(f(i,j),p));
				if(j>1)
					G[f(i,j-2)].pb(mp(f(i,j),q));
			}
			else if(s[i][j]=='L')
			{
				if(i<n-1)
					G[f(i+1,j+1)].pb(mp(f(i,j),p));
				if(i)
					G[f(i-1,j+1)].pb(mp(f(i,j),p));
				if(j<m-2)
					G[f(i,j+2)].pb(mp(f(i,j),q));
			}
			else if(s[i][j]=='D')
			{
				if(j<m-1)
					G[f(i-1,j+1)].pb(mp(f(i,j),p));
				if(j)
					G[f(i-1,j-1)].pb(mp(f(i,j),p));
				if(i>1)
					G[f(i-2,j)].pb(mp(f(i,j),q));
			}
			else if(s[i][j]=='U')
			{
				if(j<m-1)
					G[f(i+1,j+1)].pb(mp(f(i,j),p));
				if(j)
					G[f(i+1,j-1)].pb(mp(f(i,j),p));
				if(i<n-2)
					G[f(i+2,j)].pb(mp(f(i,j),q));
			}
	memset(dist,inf,sizeof(dist));
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='.')
			{
				dist[f(i,j)]=0;
				pq.push(mp(0,f(i,j)));
			}
	while(!pq.empty())
	{
		ll d=pq.top().first;
		int x=pq.top().second;
		pq.pop();
		if(dist[x]!=d)
			continue;
		for(auto pr:G[x])
			if(d+pr.second<dist[pr.first])
			{
				dist[pr.first]=d+pr.second;
				pq.push(mp(dist[pr.first],pr.first));
			}
	}
	ll ans=1ll*inf*inf;
	for(int i=0;i<n*m;i++)
		if(dist[i]+dist[i+1]<ans&&(i+1)%m)
			ans=dist[i]+dist[i+1];
	for(int i=0;i<n*m;i++)
		if(dist[i]+dist[i+m]<ans)
			ans=dist[i]+dist[i+m];
	if(ans>1000000000000000000ll)
		die("-1");
	cout<<ans<<endl;
	return 0;
}