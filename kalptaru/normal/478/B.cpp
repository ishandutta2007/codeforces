#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,l,h,d,r;
	cin>>n>>m;
	d=n/m;
	r=n%m;
	l=r*d*(d+1)/2;
	l+=((m-r)*d*(d-1)/2);
	h=(n-m)*(n-m+1)/2;
	cout<<l<<' '<<h;
	return 0;
}