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
int n;
string s[20];
void solve ()
{
	cin>>n;
	for ( int i=0; i<=n; i++ )
	{
		int cur=2*i+1;
		int z=n-i;
		for (int j=0; j<2*z; j++)
			cout<<' ';
		for ( int j=0; j<=i; j++ )
		{
			if (j>0 || i>0)
			cout<<j<<' ';
			else 
				cout<<j;
		}
		for (int j=i-1; j>=0; j--)
			if (j!=0)
			cout<<j<<' ';
			else 
			cout<<j;
		cout<<endl;
	}
	for ( int i=n-1; i>=0; i-- )
	{
		int cur=2*i+1;
		int z=n-i;
		for (int j=0; j<2*z; j++)
			cout<<' ';
		for ( int j=0; j<=i; j++ )
		{
			if (j>0 || i>0)
			cout<<j<<' ';
			else
				cout<<j;
		}
		for (int j=i-1; j>=0; j--)
			if (j>0)
			cout<<j<<' ';
			else 
			cout<<j;
		if (i>0)
		cout<<endl;
	}
}