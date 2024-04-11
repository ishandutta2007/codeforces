#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long li;
typedef double ld;
typedef pair <int, int> pi;
typedef pair <ld, ld> pld;

void solve();
int main()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve();
	return 0;
}

#define int li
int n, m;
pair < pair <int, int>, int > sell[100500];
pair < int, int > buy[100500];
vector <int> g[100500];
int used[100500];
int mt[100500];
int timer=0;

bool try_kuhn (int v)
{
	if (used[v]==timer)
		return false;
	used[v]=timer;
	for (int i=0; i<g[v].size(); i++)
	{
		int to=g[v][i];
		if (mt[to]==-1 ||  try_kuhn(mt[to]))
		{
			mt[to]=v;
			return true;
		}
	}
	return false;
}

vector < pair <int, int> > answer;

map <int, int> ret;

void solve()
{
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>sell[i].first.first>>sell[i].first.second, sell[i].second=i;
	sort (sell, sell+n);
	reverse (sell, sell+n);
	for (int i=0; i<n; i++)
		ret[sell[i].first.second]=i;
	cin>>m;
	for (int i=0; i<m; i++)
	{
		cin>>buy[i].first>>buy[i].second;
		map <int, int>::iterator j=ret.find(buy[i].second);
		if (j!=ret.end() && sell[j->second].first.first<=buy[i].first)
			g[j->second].pb(i);
		j=ret.find(buy[i].second+1);
		if (j!=ret.end() && sell[j->second].first.first<=buy[i].first)
			g[j->second].pb(i);
	}

	/*for (int i=0; i<n; i++)
		for (int j=0; j<g[i].size(); j++)
			cout<<i<<' '<<g[i][j]<<endl;*/

	memset (mt, -1, sizeof mt);
	int ans=0;
	for (int i=0; i<n; i++)
	{
		timer++;
		bool w=try_kuhn(i);
		if (w)
			ans+=sell[i].first.first;
	}

	/*set <int> tt;
	for (int i=0; i<m; i++)
		if (mt[i]!=-1)
		{
			if (tt.find(mt[i])!=tt.end())
			{
				int hhh=1, aaa=0;
				cout<<(hhh/aaa);
			}
			tt.insert(mt[i]);
		}*/

	for (int i=0; i<m; i++)
		if (mt[i]!=-1)
			answer.pb( mp( sell[mt[i]].second, i ) );
	cout<<ans<<endl;
	cout<<answer.size()<<endl;
	for (int i=0; i<answer.size(); i++)
		cout<<answer[i].second+1<<' '<<answer[i].first+1<<endl;

}