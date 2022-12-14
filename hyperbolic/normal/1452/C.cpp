#include <stdio.h>
#include <string.h>
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		int ans = 0;
		int count1 = 0, count2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='[') count1++;
			if(x[i]=='(') count2++;
			if(x[i]==']')
			{
				if(count1>0)
				{
					ans++;
					count1--;
				}
			}
			if(x[i]==')')
			{
				if(count2>0)
				{
					ans++;
					count2--;
				}
			}
		}
		printf("%d\n",ans);
	}
}