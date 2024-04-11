#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
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
int p[3], t[2], n;
pi otr[3000];
int cnt ( int z )
{
	if ( z<=t[0] )
		return z*p[0];
	if ( z<=t[1]+t[0] )
		return t[0]*p[0]+(z-t[0])*p[1];
	return t[0]*p[0]+t[1]*p[1]+(z-t[0]-t[1])*p[2];
}
void solve ()
{
    cin>>n>>p[0]>>p[1]>>p[2]>>t[0]>>t[1];
	for (int i=0; i<n; i++)
		cin>>otr[i].first>>otr[i].second;
	int ans=0;
	for (int i=0; i<n; i++)
	{
		ans+=(otr[i].second-otr[i].first)*p[0];
		if (i<n-1)
			ans+=cnt ( otr[i+1].first-otr[i].second );
	}
	cout<<ans;
}