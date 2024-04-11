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
//#define int li
int n, t;
int x[2000], a[2000];
pi good[2000];
void solve ()
{
	cin>>n>>t;
	t*=2;
	for (int i=0; i<n; i++)
	{
		cin>>x[i]>>a[i];
		good[i]=mp ( 2*x[i]-a[i], 2*x[i]+a[i] );
	}
	sort (good, good+n);
	int ans=2;
	for ( int i=0; i<n-1; i++ )
		if ( good[i+1].first>good[i].second+t )
			ans+=2;
		else
			if ( good[i+1].first-good[i].second==t )
				ans++;
	cout<<ans;
}