#include<bits/stdc++.h>
using namespace std;
#define MAXN 1048576
#define ll long long
#define P 998244353
int n,b[7005],i,j,x;
ll a[7005],y,ans;
bool v[7005];
map<ll,int> s;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
	}
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<=n;i++)if(s[a[i]]>1)
	{
		ans+=b[i];
		v[i]=1;
	}
	for(i=1;i<=n;i++)if(s[a[i]]==1)for(j=1;j<=n;j++)if((a[j]&a[i])==a[i]&&v[j])
	{
		ans+=b[i];
		break;
	}
	cout<<ans<<endl;
	return 0;
}