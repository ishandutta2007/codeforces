#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+1]; FOR(i, 0, (n)) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n)][(m)]; FOR(i, 0, (n)){FOR(j,0,(m))cin>>a[i][j];}
#define printarr(a,n) FOR(i, 0, (n)) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,0,(m))cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n;
		ll ans=0;
		cin>>n;
		readarr(a,n)
		sort(a,a+n);
		FOR(i,0,n)
		{
			if(i%2==0)
			ans+=(a[n-i-1]*a[n-i-1]);
			else
			ans-=(a[n-i-1]*a[n-i-1]);
		}
		long double d;
		d=ans*3.141592653589793238462643383279502884;
		setpre(10)
		cout<<d;
	}
}