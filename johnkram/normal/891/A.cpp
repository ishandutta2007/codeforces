#include<bits/stdc++.h>
using namespace std;
int n,a[2005],i,j,k,ans;
int gcd(int x,int y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)j=gcd(j,a[i]);
	if(j>1)
	{
		puts("-1");
		return 0;
	}
	ans=n;
	for(i=1;i<=n;i++)
	{
		for(j=i,k=0;j<=n;j++)
		{
			k=gcd(k,a[j]);
			if(k==1)break;
		}
		if(k==1)ans=min(ans,max(j-i-1,0));
		for(j=i,k=0;j;j--)
		{
			k=gcd(k,a[j]);
			if(k==1)break;
		}
		if(k==1)ans=min(ans,max(i-j-1,0));
	}
	for(i=1;i<=n;i++)ans+=a[i]!=1;
	cout<<ans<<endl;
	return 0;
}