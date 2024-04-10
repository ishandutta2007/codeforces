#include <stdio.h>

int check1[110],check2[110];
int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=9;i++) check1[i] = check2[i] = 0;
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) x[i]%=10;
		for(int i=3;i<=a;i++) check2[x[i]]++;
		check1[x[1]]++;
		for(int i=2;i<=a-1;i++)
		{
			for(int j=0;j<=9;j++)
			{
				for(int k=0;k<=9;k++)
				{
					if((x[i]+j+k)%10==3 && check1[j]>0 && check2[k]>0)
					{
						printf("YES\n");
						goto u;
					}
				}
			}
			check1[x[i]]++;
			check2[x[i+1]]--;
		}
		printf("NO\n");
		u:;
	}
}