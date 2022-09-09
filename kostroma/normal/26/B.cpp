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
//#define int li
string s;
void solve ()
{
	int del=0;
	cin>>s;
	int bal=0;
	for ( int i=0; i<s.length(); i++ )
	{
		if (s[i]=='(')
			bal++;
		else 
			bal--;
		if ( bal==-1 )
		{
			bal=0;
			del++;
		}
		if ( bal>=s.length()-i )
		{
			bal--;
			del++;
		}
		if ( bal>=s.length()-i )
		{
			bal--;
			del++;
		}
	}
	cout<<(s.length()-del);
}