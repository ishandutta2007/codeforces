#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,ans;
ll n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n%2050)
		{
			puts("-1");
			continue;
		}
		for(ans=0,n/=2050;n;n/=10)ans+=n%10;
		cout<<ans<<endl;
	}
	return 0;
}