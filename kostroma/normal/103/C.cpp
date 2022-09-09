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
int n, k, p;
void solve ()
{
	cin>>n>>k>>p;
	while ( p-- )
	{
		int cur; cin>>cur;
		if ( k==0 )
		{
			cout<<".";
			continue;
		}
		if ( k==1 )
		{
			if ( cur==n )
				cout<<"X";
			else 
				cout<<".";
			continue;
		}
		if ( k>=n-k )
		{
			if ( cur<=2*n-2*k )
			{
				if ( cur%2 )
					cout<<".";
				else 
					cout<<"X";
				continue;
			}
			else 
				cout<<"X";
			continue;
		}
		if ( n%2==0 )
		{
			if ( cur<=n-2*k+1 )
			{
				cout<<".";
				continue;
			}
			int now=cur-n+2*k-1;
			if ( now%2 )
				cout<<"X";
			else 
				cout<<".";
			continue;
		}
		else 
		{
			if ( cur<=n-2*k+2 )
			{
				cout<<".";
				continue;
			}
			if ( cur==n )
			{
				cout<<"X";
				continue;
			}
			int now=cur-n+2*k-2;
			if ( now%2 )
				cout<<"X";
			else 
				cout<<".";
		}
	}
}