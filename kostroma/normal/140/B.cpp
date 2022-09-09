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
//#define FILE "inequality"
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

//#define int li

//pair <int, int> r[100500];
int n;
int a[400];
int b[400][400];
int to[400];
int positions[400][400];
int ansto[400];
int best[400];
int pos[400];

void solve ()
{
	cin>>n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		{
			int q; cin>>q;
			b[i][j]=q-1;
			positions[i][q-1]=j;
		}
	for (int i=0; i<n; i++)
	{
		int q; cin>>q;
		a[i]=q-1;
		pos[q-1]=i;
	}

	best[0]=0;
	for (int i=1; i<n; i++)
	{
		if (pos[i]<pos[best[i-1]])
			best[i]=i;
		else
			best[i]=best[i-1];
	}

	memset (ansto, -1, sizeof ansto);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			if (j!=best[i])
				{
					if ( ansto[j]==-1 || ( positions[j][ansto[j]]>positions[j][best[i]] ))
						ansto[j]=i;
				}
			else
			{
				for (int w=0; w<n; w++)
					if ( a[w]<=i &&  a[w]!=best[i])
					{
						if ( ansto[j]==-1 || ( positions[j][ansto[j]]>positions[j][a[w]] ))
							ansto[j]=i;
						break;
					}

			}
	}

	for (int i=0; i<n; i++)
		cout<<ansto[i]+1<<' ';

}