#include<cstdio>
#include<algorithm>

int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    while(n--)
	{
		int l,t,m;
		int min,max,mid;
		scanf("%d%d%d",&l,&t,&m);
        if(a+1LL*(l-1)*b>t)
		{
			puts("-1");
			continue;
		}
		min=l;
		max=1e7;
        while(min<max)
		{
			mid=(min+max+1)/2;
			if(1LL*std::min(mid-l+1,m)*t>=(a+1LL*(l-1)*b+a+1LL*(mid-1)*b)*(mid-l+1)/2&&a+1LL*(mid-1)*b<=t)min=mid;
			else max=mid-1;
		}
		printf("%d\n",min);
	}
}