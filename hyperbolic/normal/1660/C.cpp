#include <stdio.h>
#include <string.h>

char x[200010];
int count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		int ans = 0;
		for(int j=0;j<26;j++) count[j] = 0;
		for(int i=1;i<=a;i++)
		{
			if(count[x[i]-'a']==1)
			{
				ans--;
				for(int j=0;j<26;j++) count[j] = 0;
			}
			else ans++, count[x[i]-'a']++;
		}
		printf("%d\n",ans);
	}
}