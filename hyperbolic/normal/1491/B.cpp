#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}
int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int control;
		for(int i=1;i<a;i++)
		{
			if(abs(x[i]-x[i+1])>=2)
			{
				printf("0\n");
				goto u;
			}
		}
		
		control = 0;
		for(int i=1;i<=a;i++) if(x[i]!=x[1]) control = 1;
		if(control==0) printf("%d\n",b+c<2*c?b+c:2*c);
		else printf("%d\n",b<c?b:c);
		u:;
	}
}