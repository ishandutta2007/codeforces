#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <queue>
#include <time.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef vector <int> vi;

void solve();

int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	//cin>>t;
	while (t--)
		solve();
	return 0;
}

#define int li

int q;

void solve()
{
	cin>>q;
	int n=q;
	int now=0;
	for (int i=2; i*i<=n; i++)
		if (n%i==0)
		{
			while (n%i==0)
				now++, n/=i;
		}
	if (n>1)
		now++;
	if (now<2)
	{
		cout<<"1\n0";
		return;
	}
	if (now==2)
	{
		cout<<"2";
		return;
	}
	now=0;
	int ans=1;
	n=q;
	for (int i=2; i*i<=n; i++)
		if (n%i==0)
		{
			while (n%i==0)
			{
				now++, n/=i;
				ans*=i;
				if (now==2)
				{
					cout<<"1\n"<<ans;
					return;
				}
			}
		}
	ans*=n;
	cout<<"1\n"<<ans;

}