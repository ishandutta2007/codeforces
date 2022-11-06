#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,l;
	cin>>n;
	ll a,ans[10]={0},m=998244353,t,v,o=0;
	int d[10]={0};
	for(int i=0;i<n;i++)
	{
		ll p=1;
		cin>>a;
		l=log10(a);
		d[l]+=1;
		t=0;
		for(int i=0;i<10;i++)
		{
			v=((a%10)*11*p)%m;
			t+=(v*p)%m;
			a/=10;
			if(a==0)
				{
					ans[i]+=t;
					ans[i]=ans[i]%m;
					continue;
				}
			ans[i]+=t;
			ans[i]=ans[i]%m;
			v=(a*p)%m;
			v=(v*p)%m;
			v=(v*200)%m;
			ans[i]+=v;
			ans[i]=ans[i]%m;
			p*=10;
		}	
	}
	for(int i=0;i<10;i++)
//	cout<<d[i]<<' ';
	{
		ans[i]=(ans[i]*d[i])%m;
		o+=ans[i];
	}
	cout<<(o%m);
	return 0;
}