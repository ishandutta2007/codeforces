#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll a,ans=0,m=998244353,t,v;
	for(int i=0;i<n;i++)
	{
		ll p=1;
		cin>>a;
		t=0;
		while(a)
		{
			v=(((a%10)*11*p)%m);
			t+=(v*p)%m;
			a/=10;
			p*=10;
		}
		ans+=t;
		ans=ans%m;
	}
	ans*=n;
	ans=ans%m;
	cout<<ans;
	return 0;
}