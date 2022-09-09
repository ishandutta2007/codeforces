#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;

void solve();

int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve();
	return 0;
}

//#define int li
int n;
int a[100500];
void solve()
{
	cin>>n;
	bool f=true;
	for (int i=0; i<n; i++)
	{
		cin>>a[i];
		if (a[i]!=1)
			f=false;
	}
	if (f)
	{
		for (int i=0; i<n-1; i++)
			cout<<"1 ";
		cout<<"2";
		return;
	}
	sort (a, a+n);
	int last=a[0];
	cout<<"1 ";
	for (int i=1; i<n; i++)
	{
		if ( a[i]>last )
		{
			cout<<last<<' ';
			last=a[i];
			continue;
		}
		if (a[i]!=1)
		cout<<last<<' ';
		else 
			cout<<((i<n-1)?(1):2)<<' ';
		last=a[i];
	}
}