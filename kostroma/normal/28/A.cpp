#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <li, li> vli;
typedef pair <li, li> pli;
typedef vector <int> vi;
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
        //freopen ("out.txt", "w", stdout);
#endif
        int t=1;
        while (t--)
        solve ();
}
//#define int li
int n, m;
pi gv[1000];
vector < int > pr[300500];
int used[300050];
int razn ( int u )
{
	if ( u==-1 )
		u=n-1;
	int o=(u==n-1)?0:(u+1);
	if ( gv[u].first==gv[o].first )
		return abs ( gv[u].second-gv[o].second );
	else 
		return abs ( gv[u].first-gv[o].first );
}
int ans[2000];
void solve ()
{
	cin>>n>>m;
	for ( int i=0; i<n; i++ )
		cin>>gv[i].first>>gv[i].second;
	for ( int i=0; i<m; i++ )
	{
		int q;
		cin>>q;
		pr[q].pb (i+1);
	}
	bool f=true;
	for ( int i=0; i<n; i+=2 )
	{
		int cur=razn ( i-1 )+razn (i);
		if ( pr[cur].size()>used[cur] )
		{
			ans[i]=pr[cur][used[cur]];
			used[cur]++;
		}
		else 
			f=false;
	}
	if ( f )
	{
		cout<<"YES\n";
		for ( int i=0; i<n; i+=2 )
		{
			cout<<ans[i]<<" -1 ";
		}
		return;
	}
	f=true;
	memset (used, 0, sizeof (used));
	for ( int i=1; i<n; i+=2 )
	{
		int cur=razn ( i-1 )+razn (i);
		if ( pr[cur].size()>used[cur] )
		{
			ans[i]=pr[cur][used[cur]];
			used[cur]++;
		}
		else 
			f=false;
	}
	if ( f )
	{
		cout<<"YES\n";
		for ( int i=1; i<n; i+=2 )
		{
			cout<<"-1 "<<ans[i]<<' ';
		}
		return;
	}
	cout<<"NO";
}