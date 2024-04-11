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
#include <queue>
#include <set>
#include <map>

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
//#else 
//      freopen ("input.txt", "r", stdin);
//      freopen ("output.txt", "w", stdout);
#endif
    int t=1;
	//cin>>t;
    while (t--)
    solve();
    return 0;
}
//#define int li
int n;
map <int, int> num;
void solve ()
{
	cin>>n;
	if (n%2)
	{
		cout<<"NO";
		return;
	}
	for (int i=0; i<n; i++)
	{
		int cur;
		cin>>cur;
		num[cur]++;
	}
	while ( !num.empty() )
	{
		map <int, int>::iterator curr=num.begin();
		pi cur=*curr;
		if (num.upper_bound(cur.first)==num.end())
		{
			cout<<"NO";
			return;
		}
		map <int, int>::iterator next=num.upper_bound(cur.first);
		if ( next->first!=cur.first+1 || (next->second<2 && n>2 ) )
		{
			cout<<"NO";
			break;
		}
		if (n==2)
		{
			cout<<"YES";
			return;
		}
		cur.second--;
		if ( cur.second==0 )
			num.erase(num.begin());
		else 
			num.begin()->second--;
		((num.upper_bound(cur.first))->second)--;
		n-=2;
	}
}