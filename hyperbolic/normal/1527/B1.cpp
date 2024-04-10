#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int count1 = 0, count2 = 0, count3 = 0;
		for(int i=1;i<=a;i++)
		{
			if(i>a-i+1) break;
			if(i==a-i+1 && x[i]=='0') count3++;
			else if(x[i]!=x[a-i+1]) count1++;
			else if(x[i]=='0' && x[a-i+1]=='0') count2++;
		}
		
		if(count3==0)
		{
			if(count2==0)
			{
				if(0 > count1) printf("BOB\n");
				else if(0 < count1) printf("ALICE\n");
				else printf("DRAW\n");
			}
			else
			{
				if(count1>0)
				{
					if(count2-1+1> count2+1+count1-1) printf("BOB\n");
					else if(count2-1+1< count2+1+count1-1) printf("ALICE\n");
					else printf("DRAW\n");
				}
				else printf("BOB\n");
			}
		}
		else
		{
			if(count2==0)
			{
				if(1 > count1) printf("BOB\n");
				else if(1 < count1) printf("ALICE\n");
				else printf("DRAW\n");
			}
			else
			{
				if(count2 > count2+1+count1) printf("BOB\n");
				else if(count2 < count2+1+count1) printf("ALICE\n");
				else printf("DRAW\n");
			}
		}		
	}
}