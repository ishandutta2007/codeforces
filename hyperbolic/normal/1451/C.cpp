#include <stdio.h>

int count1[30],count2[30];
char x[1000010],y[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<26;i++) count1[i] = count2[i] = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s%s",x+1,y+1);
		for(int i=1;i<=a;i++) count1[x[i]-'a']++;
		for(int i=1;i<=a;i++) count2[y[i]-'a']++;
		for(int i=0;i<=24;i++)
		{
			if(count1[i]<count2[i])
			{
				printf("NO\n");
				goto u;
			}
			else
			{
				int k = count1[i]-count2[i];
				if(k%b==0)
				{
					count1[i+1] += k;
					count1[i] -= k;
				}
				else
				{
					printf("NO\n");
					goto u;
				}
			}
		}
		if(count1[25]==count2[25]) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}