#include <stdio.h>
#include <string.h>

char x[10010];
int main()
{
	int a;
	scanf("%s",x+1);
	a = strlen(x+1);
	for(int i=1;i<=a;i++) x[i]-='0';
	for(int i=2;i<=a;i++)
	{
		x[i-1]-=1;
		x[i]+=10;
	}
	for(int i=a;i>=1;i--)
	{
		if(x[i]==19)
		{
			x[i]-=10;
			x[i-1]++;
		}
		else break;
	}
	
	int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	printf("%d",sum);
}