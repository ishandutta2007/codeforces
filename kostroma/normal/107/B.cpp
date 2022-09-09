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
int n, m, h;
int s[5000];
void solve ()
{
	cin>>n>>m>>h;
	h--;
	for ( int i=0; i<m; i++ )
		cin>>s[i];
	s[h]--;
	n--;
	int sum1=0, sum2=0;
	for (int i=0; i<m; i++)
		sum1+=s[i];
	if (sum1<n)
	{
		cout<<"-1";
		return;
	}
	for (int i=0; i<m; i++)
		if (i!=h)
			sum2+=s[i];
	ld ans=1;
	for ( int i=sum2+1; i<=sum1; i++ )
	{
		ld dob=(ld)n/i;
		dob=1-dob;
		ans*=dob;
	}
	printf ("%.8Lf", 1-ans);
}