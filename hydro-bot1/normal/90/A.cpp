// Hydro submission #627a5cf192557d8f7b9fec4f@1652186354077
#include<bits/stdc++.h>
using namespace std;
int a[4],t,z,x,ans;
int main()
{
	cin>>a[1]>>a[2]>>a[3];
	z=a[1]+a[2]+a[3];
	for(int j=1;j<=9999;j++)
	{
		for(int i=1;i<=3;i++)
		{
			x=i;
			if(a[i]>=2)
			{
				a[i]-=2;
				z-=2;
				ans++;
			}
			else
			{
				z-=a[i];
				a[i]=0;
				ans++;
			}
			if(z==0) break;
		}
		if(z==0) break;
	}
    printf("%d\n",ans+29);
    return 0;
}