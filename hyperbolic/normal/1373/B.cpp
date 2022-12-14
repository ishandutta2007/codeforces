#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		int s1 = 0, s2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='0') s1++;
			else s2++;
		}
		int t = s1<s2?s1:s2;
		printf("%s\n",t%2==0?"NET":"DA");
	}
}