#include <stdio.h>
#include <string.h>

char x[1010],y[1010];

int func(int k)
{
	int count = 0;
	for(int i=1;i<=k;i++) if(x[i]!=y[i]) count++;
	return count;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		if(a<=2)
		{
			printf("0\n");
			continue;
		}
		
		int ans = 12345678;
		for(int i=1;i<=a;i++) y[i] = '0';
		int s = func(a);
		ans = ans<s?ans:s;
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]==y[i]) s++;
			else s--;
			ans = ans<s?ans:s;
		}
		
		for(int i=1;i<=a;i++) y[i] = '1';
		s = func(a);
		ans = ans<s?ans:s;
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]==y[i]) s++;
			else s--;
			ans = ans<s?ans:s;
		}
		
		printf("%d\n",ans);
	}
}