#include <stdio.h>
int x[100010];
int main()
{
	int a,b,c,i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<=a;i++) scanf("%d",&x[i]);
	int s=0,t=1;
	long long int count = 0;
	while(1)
	{
		if(t>a&&s==0)
		{
			printf("%I64d",count);
			return 0;
		}
		while(t<=a&&s+x[t]<=b) s+=x[t],t++;
		if(s<c)
		{
			count++;
			s=0;
		}
		else
		{
			count += (s/c);
			s = s%c;
		}
	}
}