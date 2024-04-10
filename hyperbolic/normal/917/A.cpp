#include <stdio.h>
#include <string.h>
char x[5010];
int a,check[5010][5010];
int main()
{
	scanf("%s",x+1);
	a = strlen(x+1);
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		int min, max, free;
		min = max = free = 0;
		for(int j=i;j+1<=a;j+=2)
		{
			if(x[j]=='?') min--,max++,free++;
			if(x[j]=='(') min++,max++;
			if(x[j]==')') min--,max--;
			
			if(max<0) break;
			if(min<0)
			{
				if(free>0) free--, min+=2;
				else break;
			}
			
			if(x[j+1]=='?') min--,max++,free++;
			if(x[j+1]=='(') min++,max++;
			if(x[j+1]==')') min--,max--;
			
			if(max<0) break;
			if(min<0)
			{
				if(free>0) free--, min+=2;
				else break;
			}
			if(min==0) count++;
		}
	}
	printf("%d",count);
}