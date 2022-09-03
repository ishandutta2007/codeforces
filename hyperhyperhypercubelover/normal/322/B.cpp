#include<cstdio>

int main()
{
	int now,max=0;
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	now=0;
	now+=r/3;
	now+=g/3;
	now+=b/3;
	if(now>max)max=now;
	if(r&&g&&b)
	{
		now=1;
		now+=(r-1)/3;
		now+=(g-1)/3;
		now+=(b-1)/3;
		if(now>max)max=now;
	}
	if(r>=2&&g>=2&&b>=2)
	{
		now=2;
		now+=(r-2)/3;
		now+=(g-2)/3;
		now+=(b-2)/3;
		if(now>max)max=now;
	}
	printf("%d",max);
}