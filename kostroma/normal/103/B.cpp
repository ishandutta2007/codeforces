#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve ();
	return 0;
}
//caution: is int really int?
//#define int li
int n, m;
vector <int> e[200];
bool be[200];
void dfs1 (int v, int beg=-1, int end=-1)
{
	//cout<<beg<<' '<<end<<endl;
	be[v]=true;
	for ( int i=0; i<e[v].size(); i++ )
		if ( (v!=beg || e[v][i]!=end) && (v!=end || e[v][i]!=beg))
		if ( !be[e[v][i]] )
			dfs1(e[v][i], beg, end);
}
vector <pi> nemost;
void solve ()
{
	cin>>n>>m;
	for ( int i=0; i<m; i++ )
	{
		int q, w; cin>>q>>w;
		e[q-1].pb(w-1); e[w-1].pb(q-1);
	}
	dfs1(0);
	for ( int i=0; i<n; i++ )
		if ( !be[i] )
		{
			cout<<"NO";
			return;
		}
	memset (be, false, sizeof(be));
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<e[i].size(); j++ )
			if ( i<e[i][j] )
		{
			bool flag=true;
			dfs1 (0, i, e[i][j]);
			for ( int k=0; k<n; k++ )
				if ( !be[k] )
				{
					flag=false;
					break;
				}
			if ( flag )
				nemost.pb ( mp ( i, e[i][j] ) );
			memset (be, false, sizeof(be));
		}
	int r=nemost.size();
	int step[200];
	memset (step, 0, sizeof (step));
	for (int i=0; i<r; i++)
	{
		step[nemost[i].first]++;
		step[nemost[i].second]++;
		//cout<<nemost[i].first<<' '<<nemost[i].second<<endl;
	}
	if ( nemost.size()<3 )
	{
		cout<<"NO";
		return;
	}
	for ( int i=0; i<n; i++ )
		if ( step[i]!=0 && step[i]!=2 )
		{
			cout<<"NO";
			return;
		}
	cout<<"FHTAGN!";
}