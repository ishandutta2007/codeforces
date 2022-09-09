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

int a[3000];
string s;

void solve ()
{
	cin>>s;
	for (int i=0; i<s.length(); i++)
		a[s[i]]++;
	cin>>s;
	for (int i=0; i<s.length(); i++)
		a[s[i]]++;
	cin>>s;
	for (int i=0; i<s.length(); i++)
		a[s[i]]--;
	for (int i=0; i<300; i++)
		if (a[i]!=0)
			{
				cout<<"NO";
				return;
			}
	cout<<"YES";
}