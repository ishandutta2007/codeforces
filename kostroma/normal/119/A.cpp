#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
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
//#define int li //    !
int a, b, n;
int gcd (int q, int w)
{
	if (q<w)
		swap (q, w);
	while (w>0)
	{
		q%=w;
		swap (q, w);
	}
	return q;
}
void solve ()
{
	cin>>a>>b>>n;
	for (int i=0; i<200; i++)
	if (i%2==0)
	{
		int cur=gcd (n,a);
		if (cur>n)
		{
			cout<<"1";
			return;
		}
		n-=cur;
	}
	else 
	{
		int cur=gcd (n,b);
		if (cur>n)
		{
			cout<<"0";
			return;
		}
		n-=cur;
	}
}