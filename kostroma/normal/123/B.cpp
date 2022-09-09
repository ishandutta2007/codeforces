#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
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
int main ()
{
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}
#define int li
#define x0 gghh
#define y0 gghhh
#define x1 ggh
#define y1 gg


int x0, y0, x1, y1;
int a, b;
void solve ()
{
	cin>>a>>b>>x0>>y0>>x1>>y1;
	int za=(x0+y0)/(2*a);
	if ( za*(2*a)>x0+y0 )
		za--;
	int zb=(x0-y0)/(2*b);
	if ( zb*(2*b)>x0-y0 )
		zb--;

	int ta=(x1+y1)/(2*a);
	if ( ta*(2*a)>x1+y1 )
		ta--;
	int tb=(x1-y1)/(2*b);
	if ( tb*(2*b)>x1-y1 )
		tb--;

	//cout<<za<<' '<<zb<<' '<<ta<<' '<<tb<<endl;

	int z=za-ta, t=zb-tb;
	if (z<0)
		z=-z;
	if (t<0)
		t=-t;
	cout<<max(z, t);
}