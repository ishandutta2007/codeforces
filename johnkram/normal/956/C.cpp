#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
int n,m[100005],i,j,a[100005];
bool b;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		m[i]=max(m[i-1],a[i]);
		if(m[i]==a[i])m[i]++;
	}
	for(i=n;i;i--)m[i-1]=max(m[i-1],m[i]-1);
	for(i=1;i<=n;i++)ans+=m[i]-a[i]-1;
	cout<<ans<<endl;
	return 0;
}