#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;

void solve ();

int main ()
{
#ifdef _DEBUG
	freopen ("in.txt","r",stdin);
#endif
	solve ();
	return 0;
}
#define int li
int n, sum=0;
int a[100500];
int numpref[100500];
bool goodpref[100500];
int numsuf[100500];
bool goodsuf[100500];
void solve()
{
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if (sum%3)
	{
		cout<<"0";
		return;
	}
	int s=0;
	for ( int i=0; i<n; i++ )
	{
		s+=a[i];
		if (s*3==sum)
			goodpref[i]=true;
	}
	s=0;
	for (int i=n-1; i>=0; i--)
	{
		s+=a[i];
		if (s*3==sum)
			goodsuf[i]=true;
	}
	numpref[0]=goodpref[0];
	for ( int i=1; i<n; i++ )
		numpref[i]=numpref[i-1]+goodpref[i];
	numsuf[n-1]=goodsuf[n-1];
	for ( int i=n-2; i>=0; i-- )
		numsuf[i]=numsuf[i+1]+goodsuf[i];

	int ans=0;
	for ( int i=0; i<n-2; i++ )
		ans+=goodpref[i]*numsuf[i+2];
	cout<<ans;
}