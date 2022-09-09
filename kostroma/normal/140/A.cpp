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
int n, R, r;

void solve ()
{
	cin>>n>>R>>r;
	if (r>R)
	{
		cout<<"NO";
		return;
	}
	if (r*2>R)
	{
		if (n==1)
			cout<<"YES";
		else
			cout<<"NO";
		return;
	}
	if (r*2==R)
	{
		if (n<=2)
			cout<<"YES";
		else
			cout<<"NO";
		return;
	}

	ld z=(ld)R;
	z*=(ld)R-2*r;
	z=sqrt(z);
	ld u=(ld)r;
	z=u/z;

	z=atan (z);

	ld nn= (ld)n;

	if ( z < M_PI/nn + 1e-30 )
		cout<<"YES";
	else
		cout<<"NO";

}