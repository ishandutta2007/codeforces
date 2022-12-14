#include <stdio.h>

char x[100010];
int count[30];
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
		
		int start = 0;
		for(int i=0;i<26;i++)
		{
			if(count[i]>0)
			{
				start = i;
				break;
			}
		}
		
		if(count[start]<b)
		{
			int s = 0;
			for(int i=start;i<26;i++)
			{
				s += count[i];
				if(s>=b)
				{
					printf("%c\n",'a'+i);
					goto u;
				}
			}
		}
		else
		{
			printf("%c",'a'+start);
			count[start] -= b;
			
			int type = 0;
			for(int i=start;i<26;i++) if(count[i]>0) type++;
			if(type==0)
			{
				printf("\n");
				goto u;
			}
			else if(type==1)
			{
				for(int i=start;i<26;i++)
				{
					if(count[i]>0)
					{
						int t = (a-b-1)/b + 1;
						while(t--) printf("%c",'a'+i);
						printf("\n");
						goto u;
					}
				}
			}
			else
			{
				for(int i=start;i<26;i++) while(count[i]--) printf("%c",'a'+i);
				printf("\n");
				goto u;
			}
		}
		
		u:;
	}
}