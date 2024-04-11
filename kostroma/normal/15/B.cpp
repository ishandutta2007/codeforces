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

void solve ()
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
		if ( 2*x<=n && 2*y<=m )
		{
			cout<<2*x*y<<endl;
			continue;
		}
		if ( 2*x>n && 2*y>m )
		{
		int z=(2*x-n)*(2*y-m);
		cout<<2*x*y-z<<endl;
		continue;
		}
		if (2*x>n)
		{
			cout<<(2*x-n)*(m-2*y)+2*x*y<<endl;
			continue;
		}
		if (2*y>m)
		{
			cout<<(2*y-m)*(n-2*x)+2*x*y<<endl;
			continue;
		}
	}
}