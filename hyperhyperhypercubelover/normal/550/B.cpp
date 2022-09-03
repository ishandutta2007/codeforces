#include<cstdio>

int a[22];

int main()
{
	int res=0;
	int max,min;
	int cnt,sum;
	int i,j,n,l,r,x;
	scanf("%d%d%d%d",&n,&l,&r,&x);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<(1<<n);i++)
	{
		cnt=sum=max=0;
		min=1e9;
		for(j=0;j<n;j++)if((i>>j)&1)
		{
            cnt++;
            sum+=a[j];
            if(a[j]>max)max=a[j];
            if(a[j]<min)min=a[j];
		}
        if(cnt>=2&&sum>=l&&sum<=r&&max-min>=x)res++;
	}
	printf("%d",res);
}