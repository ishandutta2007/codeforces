#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
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
int n, m, tin[100500], fup[100500];
vector <int> e[100500];
bool used[100500];
int timer=0;
bool flag=true;
void dfs (int v, int p=-1)
{
	used[v]=true;
	tin[v]=fup[v]=timer++;
	for (int i=0; i<e[v].size(); i++)
	{
		int to=e[v][i];
		if ( to==p )
			continue;
		if (used[to])
			fup[v]=min (fup[v], tin[to]);
		else 
		{
			dfs (to, v);
			fup[v]=min (fup[v], fup[to]);
			if ( fup[to]>tin[v] )
			{
				flag=false;
			}
		}
	}
}
vector <pi> ans;
bool used1[100500];
void dfs1 (int v, int p=-1)
{
	used1[v]=true;
	for ( int i=0; i<e[v].size(); i++ )
		if ( !used1[e[v][i]] )
		{
			ans.pb ( mp (v, e[v][i]) );
			dfs1(e[v][i], v);
		}
		else
			if (p!=e[v][i] && tin[v]<tin[e[v][i]])
		{
			ans.pb (mp (e[v][i], v) );
		}
}
void solve ()
{
      cin>>n>>m;
	  for (int i=0; i<m; i++)
	  {
		  int q, w;
		  scanf ("%d%d", &q, &w);
		  e[q-1].pb (w-1);
		  e[w-1].pb (q-1);
	  }
	dfs (0);
	if(!flag)
	{
		cout<<"0";
		return;
	}
	dfs1(0);
	for (int i=0; i<ans.size(); i++)
		cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
}