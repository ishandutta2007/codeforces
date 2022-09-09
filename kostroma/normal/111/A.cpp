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
//caution: is int really int? //    !
#define int li
int n, x, y;
void solve ()
{
	cin>>n>>x>>y;
	if (y<=n-1)
	{
		cout<<"-1";
		return;
	}
	int ans=(y-n+1)*(y-n+1)+n-1;
	if (ans>=x)
	{
		cout<<y-n+1<<endl;
		for (int i=0; i<n-1; i++)
			cout<<"1\n";
		return;
	}
	cout<<"-1";
}