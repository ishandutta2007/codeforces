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
int n;
int a[200];

void solve ()
{
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i];
	sort (a, a+n);
	int cursum=0;
	for (int j=0; j<n; j++)
	{
		cursum+=a[j];
		if (cursum>710)
		{
			n=j;
			break;
		}
	}
	int timer=350;
	int u=-1;
	for (int i=0; i<n; i++)
	{
		timer-=a[i];
		if (timer<0)
		{
			a[i]=-timer, timer=0;
			u=i;
			break;
		}
	}
	if (u==-1)
	{
		cout<<n<<" 0";
		return;
	}

	sort (a+u, a+n);
	int ans=0;
	for (int i=u; i<n; i++)
	{
		timer+=a[i];
		ans+=timer;
	}
	cout<<n<<' '<<ans;
}