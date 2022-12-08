#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a,b;

int main()
{
	scanf("%lld%lld",&a,&b);
	ll j=b/2;
	if(b%2==0)j++;
	else j++;
	//cout<<j;
	ll ans=0;
	if(b<=a)ans=b-j;
	else ans=a-j+1;
	if(ans<0)ans=0;
	printf("%lld\n",ans);
}