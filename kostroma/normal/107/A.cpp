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
//caution: is int really int?
//#define int li
int n, p;
pair <int, int> d[2000];
int iz[2000], v[2000];
bool be[2000];
void solve ()
{
	cin>>n>>p;
	for ( int i=0; i<p; i++ )
	{
		int q, w, r;
		cin>>q>>w>>r;
		q--; w--;
		d[q]=mp (w, r);
		iz[q]++; v[w]++;
	}
	int ans=0;
	for ( int i=0; i<n; i++ )
		if ( !v[i] && iz[i])
			ans++;
	cout<<ans<<endl;
	for ( int i=0; i<n; i++ )
		if ( !v[i] && iz[i])
	{
		int cur=i;
		int mn=1<<30;
		while ( iz[cur]!=0 )
		{
			mn=min (d[cur].second, mn);
			cur=d[cur].first;
		}
		cout<<i+1<<' '<<cur+1<<' '<<mn<<endl;
	}
}