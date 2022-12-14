#include <stdio.h>

char x[110];
int count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=0;i<=26;i++) count[i] = 0;
		int ans = a;
		for(int i=1;i<=a;i++)
		{
			if(count[x[i]-'A']==0) ans++;
			count[x[i]-'A'] = 1;
		}
		printf("%d\n",ans);
	}
}