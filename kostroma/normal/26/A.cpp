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
int n;
bool prost[4000];
void solve ()
{
	memset (prost, true, sizeof prost);
	prost[0]=prost[1]=false;
	for ( int i=2; i<=3000; i++ )
		if ( prost[i] )
			for (int j=2*i; j<=3000; j+=i)
				prost[j]=false;
	cin>>n;
	int ans=0;
	for ( int i=2; i<=n; i++ )
	{
		for (int j=2; j*j<=i; j++)
			if ( prost[j] && i%j==0 )
			{
				int k=i;
				while (k%j==0)
					k/=j;
				if (prost[k])
					ans++;
				for ( int z=2; z*z<=k; z++ )
					if ( prost[z] && k%z==0 )
					{
						while (k%z==0)
							k/=z;
						if (k==1)
							ans++;
						break;
					}
				break;
			}
	}
	cout<<ans;
}