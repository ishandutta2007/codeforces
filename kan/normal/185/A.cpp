#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll mod=1000000007;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

ll a[64];

int main()
{
	ll n;
	cin >> n;
	if (n==0)
	{
		cout << 1 << endl;
		return 0;
	}
	ll nwas=n;
	ll k=1;
	a[0]=2;
	int t=0;
	while (k<n)
	{
// 		cerr << "sagf" << endl;
		k*=2;
		t++;
		a[t]=(a[t-1]*a[t-1])%mod;
	}
	ll sum=1;
	for (int i=0;i<=t;i++)
	{
		if (n%2==1) sum=(sum*a[i])%mod;
		n/=2;
	}
// 	cout << sum << endl;
	ll sum2=(sum+1)%mod;
	sum=1;
	nwas--;
	for (int i=0;i<=t;i++)
	{
		if (nwas%2==1) sum=(sum*a[i])%mod;
		nwas/=2;
	}
// 	cout << sum << ' ' << sum2 << endl;
	cout << (sum*sum2)%mod << endl;
	return 0;
}