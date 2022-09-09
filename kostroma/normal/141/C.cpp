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
//#define FILE "matrixmaze"
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

//#define int li // DON'T HACK on LONG LONG!

int n;
pair <int, string> a[4000];
bool done[4000];
vector < pair <string, int> > ans;

void solve ()
{
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i].second>>a[i].first;
	sort (a, a+n);
	reverse (a, a+n);

	for ( int i=0; i<n; i++ )
	{
		if (a[i].first>n-1-i)
		{
			cout<<"-1";
			return;
		}
		int u=0;
		int need=n-i-a[i].first;
		for (int j=0; j<n; j++)
			if (!done[j])
			{
				u++;
				if (u==need)
				{
					done[j]=true;
					ans.pb (mp (a[i].second, j));
				}
			}
	}
	for (int i=ans.size()-1; i>=0; i--)
		cout<<ans[i].first<<' '<<ans[i].second+10<<endl;
}