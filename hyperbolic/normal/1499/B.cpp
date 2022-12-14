#include <stdio.h>
#include <string.h>

char x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		int R = a, L = 1;
		for(int i=1;i<a;i++)
		{
			if(x[i]=='1'&&x[i+1]=='1')
			{
				R = i;
				break;
			}
		}
		for(int i=a;i>=2;i--)
		{
			if(x[i]=='0'&&x[i-1]=='0')
			{
				L = i-1;
				break;
			}
		}
		
		if(L>R) printf("NO\n");
		else printf("YES\n");
	}
}