#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
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
//caution: is int really int? //    !
//#define int li
int n;
int x[100500], y[100500];
vector <int> del[100500];
int bs (int val, int num)
{
	int l=0, r=del[num].size();
	while (l+1<r)
	{
		//cout<<l<<' '<<r<<endl;
		int m=l+r; m/=2;
		if (del[num][m]>=val)
			r=m;
		else 
			l=m;
	}
	if (del[num][l]<val)
	return del[num][l];
	else 
		return -1;
}
void solve ()
{
	cin>>n;
	for (int i=0; i<n; i++)
		scanf ("%d%d", &x[i], &y[i]);
	for ( int i=0; i<n; i++ )
	{
		int cur=x[i];
		for ( int j=1; j*j<=x[i]; j++ )
			if (cur%j==0)
			{
				del[j].pb (i);
				if (j*j!=cur)
				{
					del[cur/j].pb (i);
				}
			}
	}
	for ( int i=0; i<n; i++ )
	{
		int beg=i-y[i];
		int ans=0;
		for ( int j=1; j*j<=x[i]; j++ )
			if (x[i]%j==0)
			{
				int now=bs (i, j);
				//cout<<now<<endl;
				if (now>=beg)
				{}
				else 
				ans++;
				if (j*j!=x[i])
				{
				now=bs (i, x[i]/j);
				if (now>=beg)
				{}
				else 
				ans++;
				}
			}
		cout<<ans<<endl;
	}
}