#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
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
	solve();
	return 0;
}
//#define int li
int n, b[3000], d;
void solve ()
{
	cin>>n>>d;
	for (int i=0; i<n; i++)
		cin>>b[i];
	int ans=0;
	for ( int i=1; i<n; i++)
	{
		int z=b[i]-b[i-1];
		if ( z>0 )
			continue;
		else 
		{
			z=-z;
			ans+=z/d+1;
			b[i]+=(z/d+1)*d;
		}
	}
	cout<<ans;
}