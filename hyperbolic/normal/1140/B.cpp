#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int ans = a-1;
		for(int i=1;i<=a;i++) if(x[i]=='>') ans = ans<i-1?ans:i-1;
		for(int i=1;i<=a;i++) if(x[i]=='<') ans = ans<a-i?ans:a-i;
		printf("%d\n",ans);
	}
}