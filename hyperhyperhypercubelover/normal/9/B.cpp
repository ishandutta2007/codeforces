#include<cstdio>
#include<cmath>

int t[100];

int main()
{
	double min=1e18;
    int i,n,a,b,mini,x,y;
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i<n;i++)scanf("%d",&t[i]);
    scanf("%d%d",&x,&y);
    for(i=n-1;i>0;i--)
	{
        if(1.*t[i]/a+sqrt(1LL*(t[i]-x)*(t[i]-x)+1LL*y*y)/b<min)
		{
			min=1.*t[i]/a+sqrt(1LL*(t[i]-x)*(t[i]-x)+1LL*y*y)/b;
			mini=i;
		}
	}
	printf("%d",mini+1);
}