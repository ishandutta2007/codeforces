#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <li, li> vli;
typedef pair <li, li> pli;
typedef vector <int> vi;
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
        //freopen ("out.txt", "w", stdout);
#endif
        int t=1;
        while (t--)
        solve ();
}
//#define int li
int n, love[200], p[200];
int need[200];
int matrix[200][200];
void solve ()
{
	cin>>n;
	for ( int i=0; i<n; i++ )
	{
		cin>>p[i];
		p[i]--;
		need[p[i]]=i;
	}
	for ( int i=0; i<n; i++ )
		cin>>love[i];
	for ( int i=0; i<n; i++ )
	{
		matrix[i][i]=1;
		int cur=love[i];
		if ( i-cur>=0 )
		{
			matrix[i][i-cur]=1;
			matrix[i-cur][i]=1;
		}
		if ( i+cur<n )
		{
			matrix[i][i+cur]=1;
			matrix[i+cur][i]=1;
		}
	}
	for ( int z=0; z<n; z++ )
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
				if ( matrix[i][z]==1 && matrix[z][j]==1 )
				{
					matrix[i][j]=1;
					matrix[j][i]=1;
				}
	for ( int i=0; i<n; i++ )
	{
		int cur=need[i];
		if ( matrix[i][cur]==0 )
		{
			cout<<"NO";
			//cout<<i<<' '<<need[i]<<endl;
			return;
		}
	}
	cout<<"YES";
}