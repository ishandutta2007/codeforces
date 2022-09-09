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
int n, k;
int done[150][150];
int good[150];
int yl[150], yr[150];
void solve ()
{
    cin>>n>>k;
	while (n--)
	{
		memset (good, -1, sizeof good);
		memset (yl, -1, sizeof yl);
		memset (yr, -1, sizeof yr);
		int m;
		cin>>m;
		for ( int i=1; i<=k; i++ )
		{
			int now=0;
			for (int j=1; j<=m; j++)
				if (done[i][j])
					now++;
			int beg=1, end=m;
			if ( now==0 )
				{
					if (min ( beg, k-end+1 )>good[i])
					{
						good[i]=min ( beg, k-end+1 );
						//cout<<good[i]<<endl;
						yl[i]=beg;
						yr[i]=end;
					}
				}
			while ( end<k )
			{
				if (done[i][beg])
					now--;
				if ( done[i][end+1] )
					now++;
				beg++;
				end++;
				if ( now==0 )
				{
					if (min ( beg, k-end+1 )>good[i])
					{
						good[i]=min ( beg, k-end+1 );
						yl[i]=beg;
						yr[i]=end;
					}
				}
			}
		}
		pair <pi, int> best=mp (mp (-1, -1), -1);
		int ras=1<<30;
		for ( int i=1; i<=k; i++ )
			if ( good[i]!=-1 )
			{
				int curans=0;
				for ( int j=yl[i]; j<=yr[i]; j++ )
					curans+=(abs(j-(k+1)/2)+abs(i-(k+1)/2));
				if ( curans<ras )
				{
					ras=curans;
					best=mp (mp (i,  yl[i]), yr[i] );
				}
			}
		if (best.first.first!=-1)
		{
			for ( int i=best.first.second; i<=best.second; i++ )
				done[best.first.first][i]=1;
			cout<<best.first.first<<' '<<best.first.second<<' '<<best.second<<endl;
		}
		else 
			cout<<"-1\n";
	}
}