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
int n;
void solve ()
{
	cin>>n;
	int ans=-1;
	for (int i=0; i<7; i++)
		if ((4*i-n)%7==0)
		{
			ans=i;
			break;
		}
	if (ans==-1)
	{
		cout<<"-1";
		return;
	}
	int ans1=n-4*ans; ans1/=7;
	if (ans1<0)
	{
		cout<<"-1";
		return;
	}
	for (int i=0; i<ans; i++)
		cout<<"4";
	for (int i=0; i<ans1; i++)
		cout<<"7";
}