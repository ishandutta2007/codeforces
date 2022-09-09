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
//#else 
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
#endif
	int t=1;
	while (t--)
    solve();
    return 0;
}
//#define int li
int n;
int c[3000][3000];
bool stolb[3000], str[3000];
int get_value ( int i, int j )
{
	return (c[i][j]+(int)str[i]+(int)stolb[j])%2;
}
void solve ()
{
	cin>>n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			scanf ("%1d", &c[i][j]);
	int ans=0;
	for ( int cur=0; cur<n; cur++ )
	{
		c[cur][cur]=get_value(cur, cur);
		str[cur]=0;
		for ( int i=n-1; i>cur; i-- )
		{
			if ( get_value ( cur, i ) )
			{
				ans++;
				str[cur]=!str[cur];
				stolb[i]=!stolb[i];
			}
		}
		stolb[cur]=0;
		for (int i=n-1; i>cur; i--)
			if (get_value (i, cur))
			{
				ans++;
				stolb[cur]=!stolb[cur];
				str[i]=!str[i];
			}
		if (get_value (cur, cur))
			ans++;
	}
	cout<<ans;
}