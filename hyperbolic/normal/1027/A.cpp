#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int b = (a/2);
		for(int i=1;i<=b;i++)
		{
			int t = (int)x[i]-(int)x[a-i+1];
			if(t==-2||t==0||t==2);
			else
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}