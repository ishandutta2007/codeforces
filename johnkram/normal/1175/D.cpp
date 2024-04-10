#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[300005],ans;
int n,m,i;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%I64d",a+i);
	for(i=n;i;i--)a[i]+=a[i+1];
	sort(a+2,a+n+1,greater<ll>());
	for(i=1;i<=m;i++)ans+=a[i];
	cout<<ans<<endl;
	return 0;
}