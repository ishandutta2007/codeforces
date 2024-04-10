#include <stdio.h>

char x[200010];
int check[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	
	int max = 0;
	for(int i=0;i<26;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(x[j]=='a'+i) check[j] = 1;
			else check[j] = 0;
		}
		for(int j=1;j<=a;j++) check[j] += check[j-1];
		
		int p = b;
		int count = 0;
		while(p<=a)
		{
			if(check[p]-check[p-b]==b)
			{
				count++;
				p += b;
			}
			else p++;
		}
		max = max>count?max:count;
	}
	printf("%d",max);
}