#include <bits/stdc++.h>

using namespace std;

long long n,i,j,c[200005],a[200005],ans,mx,x,y;

int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&c[i]);
		for (j=1;j<=c[i];j++)
		{
			scanf("%I64d",&x);
			a[i]=max(a[i],x);
			
		}
		
		mx=max(mx,a[i]);
		
	}
	
	for (i=1;i<=n;i++)
	{
		ans+=(mx-a[i])*c[i];
	}
	
	cout<<ans<<endl;
	
}