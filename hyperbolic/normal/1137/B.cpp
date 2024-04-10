#include <stdio.h>
#include <string.h>

char x[500010],y[500010];
int fail[500010];

int main()
{
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	int b = strlen(y+1);
	
	int count0 = 0, count1 = 0 ,count2 = 0 ,count3 = 0, count4 = 0 ,count5 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='0') count0++;
		else count1++;
	}
	
	for(int i=1;i<=b;i++)
	{
		if(y[i]=='0') count2++;
		else count3++;
	}
	
	fail[1] = 0;
	for(int i=2;i<=b;i++)
	{
		int t = fail[i-1];
		while(1)
		{
			if(t==0)
			{
				if(y[1]==y[i])
				{
					fail[i] = 1;
					break;
				}
				else
				{
					fail[i] = 0;
					break;
				}
			}
			else
			{
				if(y[i]==y[t+1])
				{
					fail[i] = t+1;
					break;
				}
				else t = fail[t];
			}
		}
	}
	
	for(int i=fail[b]+1;i<=b;i++)
	{
		if(y[i]=='0') count4++;
		else count5++;
	}
	
	if(count0>=count2&&count1>=count3)
	{
		for(int i=1;i<=b;i++) printf("%c",y[i]);
		count0 -= count2;
		count1 -= count3;
		while(1)
		{
			if(count0>=count4&&count1>=count5)
			{
				for(int i=fail[b]+1;i<=b;i++) printf("%c",y[i]);
				count0 -= count4;
				count1 -= count5;
			}
			else
			{
				for(int i=1;i<=count0;i++) printf("0");
				for(int i=1;i<=count1;i++) printf("1");
				return 0;
			}
		}
	}
	else
	{
		for(int i=1;i<=a;i++) printf("%c",x[i]);
		return 0;
	}
}