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

int n;
vector <int> del;
void solve ()
{
	cin>>n;
	for (int i=1; i*i<=n; i++)
		if (n%i==0)
		{
			del.pb (i);
			if (i*i!=n)
				del.pb (n/i);
		}
	int mn=1LL<<60, mx=0;
	for (int i=0; i<del.size(); i++)
		for (int j=0; j<del.size(); j++)
		{
			int m=del[i]*del[j];
			if (n%m)
				continue;
			int r=n/m;
			int z=del[i]+1;
			z*=del[j]+2;
			z*=r+2;
			int cur=z-n;
			mn=min (mn, cur);
			mx=max(mx, cur);
		}
	cout<<mn<<' '<<mx;
}