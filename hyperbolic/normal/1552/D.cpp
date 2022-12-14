#include <stdio.h>

int a,x[110];
int func(int k, int sum)
{
	if(k>a)
	{
		if(sum==0) return 1;
		else return 0;
	}
	
	int s1 = func(k+1,sum-x[k]);
	int s2 = func(k+1,sum+x[k]);
	int s3 = func(k+1,sum);
	if(s1==1) return 1;
	if(s2==1) return 1;
	if(s3==1) return 1;
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++)
		{
			if(func(i+1,x[i])==1)
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}