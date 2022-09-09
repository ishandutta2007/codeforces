#pragma comment(linker, "/STACK:64000000")
#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
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
//#define FILE "matrixmaze"
int main ()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
    //cout<<FILE<<endl;
#else
	//freopen (FILE ".in", "r", stdin);
	//freopen (FILE ".out", "w", stdout);
#endif
    solve();
    return 0;
}

//#define int li // DON'T HACK on LONG LONG!

int a, x, y;
int num (int z)
{
	return z+1+z/2;
}
void solve ()
{
	cin>>a>>x>>y;

	if ( y % a == 0 )
	{
		cout<<"-1";
		return;
	}

	int z=y/a;

	if (z==0 || z%2)
	{
		if ( 2*x>-a && 2*x<a )
			cout<<num(z);
		else
			cout<<"-1";
		return;
	}
	if ( x>=a || x<=-a || x==0)
	{
		cout<<"-1";
		return;
	}
	if (x>0)
		cout<<num(z-1)+2;
	else
		cout<<num(z-1)+1;
}