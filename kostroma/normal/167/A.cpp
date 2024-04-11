#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef double ld;

void solve();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int z=1;
	while (z--)
		solve();
	return 0;
}

//#define int li

int n;
ld a, d, t[100500], v[100500];

ld timer (int num)
{
	ld tt=v[num]/a;
	if ( a*tt*tt/2.0>d )
	{
		return sqrt(2.0*d/a);
	}
	else
	{
		return tt+(d-a*tt*tt/2.0)/v[num];
	}
}

ld ans[100500];

void solve()
{
	cin>>n>>a>>d;
	for (int i=0; i<n; i++)
		cin>>t[i]>>v[i];
	ans[0]=timer(0)+t[0];
	for (int i=1; i<n; i++)
		if (timer(i)+t[i]>ans[i-1])
			ans[i]=timer(i)+t[i];
		else
			ans[i]=ans[i-1];
	for (int i=0; i<n; i++)
		printf ("%.10lf\n", ans[i]);
}