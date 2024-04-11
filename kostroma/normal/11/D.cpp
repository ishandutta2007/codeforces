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
int n, m;
int e[21][21];
li dp[21][(1<<20)+1];
int var[21][1<<19];
int mini[(1<<20)];
int num[21];
void solve ()
{
    cin>>n>>m;
	for (int i=0; i<m; i++)
	{
		int q, w;
		cin>>q>>w;
		e[q-1][w-1]=1;
		e[w-1][q-1]=1;
	}
	for (int i=0; i<n; i++)
		dp[i][1<<i]=1;
	for ( int mask=1; mask<(1<<n); mask++ )
	{
		int z=0;
		bool f=false;
		for (int i=0; i<n; i++)
			if ( mask & (1<<i) )
		{	
			if (!f)
			{
				f=true;
				mini[mask]=i;
			}
			z++;
		}
		var[z][num[z]++]=mask;
	}
	li ans=0;
	for ( int k=1; k<=n; k++ )
	{
			for ( int end=0; end<n; end++ )
			{
				for ( int i=0; i<num[k]; i++ )
				{
					int mask=var[k][i];
					int beg=mini[mask];
					for ( int j=beg; j<n; j++ )
						if (e[end][j])
							{

								if ( j==beg && k!=1 && k!=2)
										ans+=dp[end][mask];
								else 
									if ( j>beg && !( mask & (1<<j) ) )
											dp[j][mask+(1<<j)]+=dp[end][mask];
							}
				}
			}
	}
	cout<<(ans/2);
}