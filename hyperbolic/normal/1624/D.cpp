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
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=0;i<26;i++) count[i] = 0;
		for(int i=1;i<=a;i++) count[x[i]-'a']++;
		
		int s1 = 0;
		for(int i=0;i<26;i++) s1 += 2*(count[i]/2);
		
		for(int i=a;i>=1;i--)
		{
			if(i%2==0)
			{
				if((long long int)i*b<=s1)
				{
					printf("%d\n",i);
					goto u;
				}
			}
			else
			{
				long long int t = (long long int)(i-1)*b;
				if(t <= s1 && (a-t)>=b)
				{
					printf("%d\n",i);
					goto u;
				}
			}
		}
		u:;
	}
}