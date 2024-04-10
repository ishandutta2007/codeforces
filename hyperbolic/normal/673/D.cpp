#include <stdio.h>

int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d",&a,&b);
	if(a==4)
	{
		printf("-1");
		return 0;
	}
	if(b<a+1)
	{
		printf("-1");
		return 0;
	}
	scanf("%d%d%d%d",&c,&d,&e,&f);
	
	printf("%d %d ",c,e);
	for(int i=1;i<=a;i++)
	{
		if(i==c) continue;
		if(i==d) continue;
		if(i==e) continue;
		if(i==f) continue;
		printf("%d ",i);
	}
	printf("%d %d\n",f,d);
	
	printf("%d %d ",e,c);
	for(int i=1;i<=a;i++)
	{
		if(i==c) continue;
		if(i==d) continue;
		if(i==e) continue;
		if(i==f) continue;
		printf("%d ",i);
	}
	printf("%d %d",d,f);
}