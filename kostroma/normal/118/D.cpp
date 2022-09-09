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
int dp[150][150][2];
int k1, k2;
int mod=100000000;
int cnt (int n1, int n2, int who)
{
	if (dp[n1][n2][who]!=-1)
		return dp[n1][n2][who];
	if ( n1==0 )
	{
		if ( n2==0 )
			return 1;
		if ( who==1 )
			return 0;
		if ( n2<=k2 )
			return 1;
		else
			return 0;
	}
	if ( n2==0 )
	{
		if ( n1==0 )
			return 1;
		if ( who==2 )
			return 0;
		if ( n1<=k1 )
			return 1;
		else
			return 0;
	}
	if (who==1)
	{
	int ans=0;
	for ( int i=1; i<=k1 && i<=n1; i++ )
	{
		ans+=cnt ( n1-i, n2, 2 );
		ans%=mod;
	}
	dp[n1][n2][who]=ans;
	return ans;
	}
	if (who==2)
	{
	int ans=0;
	for ( int i=1; i<=k2 && i<=n2; i++ )
	{
		ans+=cnt ( n1, n2-i, 1 );
		ans%=mod;
	}
	dp[n1][n2][who]=ans;
	return ans;
	}
}
void solve ()
{
	int n1, n2;
	cin>>n1>>n2>>k1>>k2;
	memset (dp, -1, sizeof (dp));
	cout<<(cnt (n1, n2, 1)+cnt(n1, n2, 2))%mod;
}