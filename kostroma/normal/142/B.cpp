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
//#define FILE "mouse"
int main ()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
   // cout<<FILE<<endl;
#else
	//freopen (FILE ".in", "r", stdin);
	//freopen (FILE ".out", "w", stdout);
#endif
	int t=1;
	while (t--)
    solve();
    return 0;
}

#define int li // DON'T HACK on LONG LONG!

int n, m;

void solve ()
{
	cin>>n>>m;
	if (n>m)
		swap (n, m);
	if (n==1)
	{
		cout<<m;
		return;
	}
	if (m==1)
	{
		cout<<n;
		return;
	}
	int ans=(m*n+1)/2;

	if (n==2)
	{
		int r=(m-m%4);
		if (m%4>=2)
			r+=4;
		if (m%4==1)
			r+=2;
		ans=max ( ans, r );
		cout<<ans;
		return;
	}

	cout<<ans;
}