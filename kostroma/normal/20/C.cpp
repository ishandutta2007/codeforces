#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;

void solve ();

int main ()
{
#ifdef _DEBUG
	freopen ("in.txt","r",stdin);
#endif
	solve ();
	return 0;
}
#define int li
int n, m;
vector < pair <int, int> > e[100500];
int pred[100500];
int dist[100500];
set < pair <int, int> > a;
void dijkstra (int v)
{
	dist[v]=0;
	pred[v]=-1;
	a.insert( mp ( 0, v ) );
	while ( !a.empty() )
	{
		pair <int, int> cur=*(a.begin());
		a.erase(a.begin());
		for ( int i=0; i<e[cur.second].size(); i++ )
		{
			int now=e[cur.second][i].first, edge=e[cur.second][i].second;
			if ( dist[now]==-1 )
			{
				pred[now]=cur.second;
				dist[now]=dist[cur.second]+edge;
				a.insert( mp (dist[now], now) );
			}
			else 
				if ( dist[now]>dist[cur.second]+edge )
				{
					a.erase( mp (dist[now], now) );
					pred[now]=cur.second;
					dist[now]=dist[cur.second]+edge;
					a.insert( mp (dist[now], now) );
				}
		}
	}
}
void solve()
{
	cin>>n>>m;
	memset (dist, -1, sizeof dist);
	for (int i=0; i<m; i++)
	{
		int q, w, r;
		cin>>q>>w>>r;
		q--; w--;
		e[q].pb(mp(w,r));
		e[w].pb(mp(q,r));
	}
	dijkstra(0);
	int now=n-1;
	if (dist[now]==-1)
	{
		cout<<"-1";
		return;
	}
	vector <int> ans;
	while (now!=-1)
	{
		ans.pb (now);
		now=pred[now];
	}
	for (int i=(int)ans.size()-1; i>=0; i--)
		cout<<ans[i]+1<<' ';
}