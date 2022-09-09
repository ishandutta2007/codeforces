#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cstdlib>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<memory.h>
#include<ctime>
#include<cctype>
using namespace std;
 /**
 CAUTION Is int really int?
 *
 Real solution after main function
 */
typedef long long li;
typedef pair <int, int> pi;
typedef pair<li, li> pli;
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
//const long double PI = 3.141592653589793238462643l;
void solve ();
 
int main()
{
        #ifdef _DEBUG
                freopen ("in.txt", "r", stdin);
        #endif
	int t=1;
	//cin>>t;
	while (t--)
    solve();
    return 0;
}

//#define int li
bool is_happy (int cur)
{
	while (cur>0)
	{
		if (cur%10!=4 && cur%10!=7)
			return false;
		cur/=10;
	}
	return true;
}
int n, k;
int a[100500];
void solve()
{
	cin>>n>>k;
	for ( int i=0; i<n; i++ )
		scanf ("%1d", &a[i]);
	for ( int i=0; i<n-1 && k>0; i++ )
	{
		if ( a[i]==4 && a[i+1]==7 )
		{
			if (i%2)
			{
				a[i]=7;
				k--;
				if (i>0 && a[i-1]==4)
				{
					if (k%2)
						a[i]=4;
					else 
						a[i]=7;
					break;
				}
				i++;
			}
			else 
			{
				a[i+1]=4;
				k--;
			}
		}
	}
	for (int i=0; i<n; i++)
		cout<<a[i];
}