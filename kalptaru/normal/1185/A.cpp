#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
ll max(ll i,ll j)
{
	if(i>j)
	return i;
	return j;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a[3],d,ans=0;
	cin>>a[0]>>a[1]>>a[2]>>d;
	sort(a,a+3);
	ans+=max((d-(a[1]-a[0])),0);
	ans+=max((d-(a[2]-a[1])),0);
	cout<<ans;
	return 0;
}