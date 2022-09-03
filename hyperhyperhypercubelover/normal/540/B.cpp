#include<cstdio>
#include<algorithm>

int a[1111];

int main()
{
	int i,n,m,l,x,y,t;
	scanf("%d%d%d%d%d",&n,&m,&l,&x,&y);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
        x-=a[i];
	}
	for(i=0;i<n-m;i++)
	{
		if(i+(n-m-i)*y<=x)break;
		a[i+m]=1;
	}
	if(i+(n-m-i)*y>x)
	{
		puts("-1");
		return 0;
	}
	t=i;
	while(i<n-m)
	{
		a[i+m]=y;
		i++;
	}
    std::sort(a,a+n);
    if(a[n/2]<y)puts("-1");
    else
	{
		for(i=0;i<t;i++)printf("1 ");
		for(i=t;i<n-m;i++)printf("%d ",y);
	}
}