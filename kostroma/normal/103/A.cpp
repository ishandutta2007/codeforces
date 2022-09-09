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
#define int li
int n;
int a[200];
void solve ()
{
	cin>>n;
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	int ans=a[0];
	for ( int i=1; i<n; i++ )
	{
		ans+=(a[i]-1)*(i+1)+1;
	}
	cout<<ans;
}