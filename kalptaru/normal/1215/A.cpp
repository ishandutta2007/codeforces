#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int a1,a2,k2,k1,n;
		cin>>a1>>a2>>k1>>k2>>n;
		int m,b=0;
		if(k2>k1)
		{
			swap(k1,k2);
			swap(a1,a2);
		}
		m=max(n-(a1*(k1-1))-(a2*(k2-1)),0);
		if(n>a2*k2)
		{
			n-=a2*k2;
			b=a2;
			b+=(n/k1);
		}
		else
		{
			b=(n/k2);
		}
		cout<<m<<' '<<b;
	}
	return 0;
}