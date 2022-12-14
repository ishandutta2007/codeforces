#include <stdio.h>

int getQuery(int a, int b, int c, int d)
{
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	
	int t;
	scanf("%d",&t);
	return t;
}

int ans[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int control = 0;
		int max;
		if(control==0)
		{
			for(int i=1;i+1<=a;i+=2)
			{
				int t = getQuery(1,i,i+1,a-1);
				if(t==a-1)
				{
					int t2 = getQuery(1,i+1,i,a-1);
					if(t2==a) control = 1;
				}
				else if(t==a) control = 1;
				if(control==1)
				{
					int p;
					for(int j=1;j<=a;j++)
					{
						if(j!=i&&j!=i+1)
						{
							p = j;
							break;
						}
					}
					int s = getQuery(1,p,i,a-1);
					if(s==a) max = i;
					else max = i+1;
					break;
				}
			}
		}
		if(control==0)
		{
			for(int i=a-1;i>=1;i-=2)
			{
				int t = getQuery(1,i,i+1,a-1);
				if(t==a-1)
				{
					int t2 = getQuery(1,i+1,i,a-1);
					if(t2==a) control = 1;
				}
				else if(t==a) control = 1;
				if(control==1)
				{
					int p;
					for(int j=1;j<=a;j++)
					{
						if(j!=i&&j!=i+1)
						{
							p = j;
							break;
						}
					}
					int s = getQuery(1,p,i,a-1);
					if(s==a) max = i;
					else max = i+1;
					break;
				}
			}
		}
		
		ans[max] = a;
		for(int i=1;i<=a;i++)
		{
			if(i==max) continue;
			ans[i] = getQuery(2,i,max,1);
		}
		
		printf("! ");
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
		fflush(stdout);
	}
}