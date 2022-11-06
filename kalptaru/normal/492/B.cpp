#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,l,p;
	double ans;
	cin>>n>>l;
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	p=max((l-a[n-1]),a[0]);
	p=p<<1;
	for(int i=1;i<n;i++)
	p=max(p,(a[i]-a[i-1]));
	ans=p;
	ans=ans/2;
	std::cout << std::fixed;
    std::cout << std::setprecision(8);
	cout<<ans;
	return 0;
}