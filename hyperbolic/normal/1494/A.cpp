#include <stdio.h>
#include <string.h>

char x[100010];
int p[6];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int count;
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=3;i++)
		{
			p[1] = 1, p[2] = 1, p[3] = 1;
			p[i] = -1;
			count = 0;
			for(int j=1;j<=a;j++)
			{
				count += p[x[j]-'A'+1];
				if(count<0) goto u;
			}
			if(count>0) continue;
			printf("YES\n");
			goto v;
			u:;
		}
		for(int i=1;i<=3;i++)
		{
			p[1] = -1, p[2] = -1, p[3] = -1;
			p[i] = 1;
			count = 0;
			for(int j=1;j<=a;j++)
			{
				count += p[x[j]-'A'+1];
				if(count<0) goto u2;
			}
			if(count>0) continue;
			printf("YES\n");
			goto v;
			u2:;
		}
		printf("NO\n");
		v:;
	}
}