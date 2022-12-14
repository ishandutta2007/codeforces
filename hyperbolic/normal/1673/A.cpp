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
		if(a==1)
		{
			printf("Bob %d\n",x[1]-'a'+1);
		}
		else if(a%2==0)
		{
			int ans = 0;
			for(int i=1;i<=a;i++) ans += (x[i]-'a'+1);
			printf("Alice %d\n",ans);
		}
		else
		{
			int s1 = 0, s2 = 0;
			for(int i=1;i<a;i++) s1 += (x[i]-'a'+1);
			for(int i=2;i<=a;i++) s2 += (x[i]-'a'+1);
			s1 -= (x[a]-'a'+1);
			s2 -= (x[1]-'a'+1);
			printf("Alice %d\n",s1>s2?s1:s2);
		}
	}
}