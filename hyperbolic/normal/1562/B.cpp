#include <stdio.h>

char x[110];
int func(int k)
{
	if(k==1) return 1;
	for(int i=2;i*i<=k;i++) if(k%i==0) return 1;
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) x[i] -= '0';
		int s;
		for(int i=1;i<=a;i++)
		{
			s = x[i];
			if(func(s))
			{
				printf("1\n");
				printf("%d\n",s);
				goto u;
			}
		}
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				s = 10*x[i]+x[j];
				if(func(s))
				{
					printf("2\n");
					printf("%d\n",s);
					goto u;
				}
			}
		}
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				for(int k=j+1;k<=a;k++)
				{
					s = 100*x[i]+10*x[j]+x[k];
					if(func(s))
					{
						printf("3\n");
						printf("%d\n",s);
						goto u;
					}
				}
			}
		}
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				for(int k=j+1;k<=a;k++)
				{
					for(int l=k+1;l<=a;l++)
					{
						s = 1000*x[i]+100*x[j]+10*x[k]+x[l];
						if(func(s))
						{
							printf("4\n");
							printf("%d\n",s);
							goto u;
						}
					}
				}
			}
		}
		u:;
	}
}