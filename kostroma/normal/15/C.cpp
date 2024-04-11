#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();
int main ()
{
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}
#define int li
void shit()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n, m, x1, y1, x2, y2;
		cin>>n>>m>>x1>>y1>>x2>>y2;
		int x=x2-x1, y=y2-y1;
		if (x<0)
			x=-x;
		if (y<0)
			y=-y;
		if ( 2*x<=n || 2*y<=m )
		{
			cout<<2*x*y<<endl;
			continue;
		}
		int z=(2*x-n)*(2*y-m);
		cout<<2*x*y-z<<endl;
	}
	
}
int val (int n)
{
	if (n==0)
		return 0;
	if (n%2)
	{
		if (n%4==3)
			return 0;
		else 
			return 1;
	}
	return val (n-1)^n;
}
void solve ()
{
	int n;
	int xor=0;
	cin>>n;
	for ( int i=0; i<n; i++ )
	{
		int x, m;
		cin>>x>>m;
		xor^=val(x-1);
		xor^=val(x+m-1);
	}
	if (xor)
		cout<<"tolik";
	else 
		cout<<"bolik";
}