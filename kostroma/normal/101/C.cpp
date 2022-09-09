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
#define int li
pli a, b, c;
void solve ()
{
	cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
	if ( c==mp(0LL,0LL) )
	{
		if ( a==b || mp(a.second, -a.first)==b || mp(-a.first, -a.second)==b || mp(-a.second, a.first)==b )
			cout<<"YES";
		else 
			cout<<"NO";
		return;
	}
	for ( int i=0; i<4; i++ )
	{
		pi need=mp ( b.first-a.first, b.second-a.second);
		int d=c.first*c.first+c.second*c.second;
		int k=need.first*c.first+need.second*c.second, l=need.first*c.second-need.second*c.first;
		if ( k%d==0 && l%d==0 )
		{
			cout<<"YES";
			return;
		}
		a=mp ( a.second, -a.first );
	}
	cout<<"NO";
}