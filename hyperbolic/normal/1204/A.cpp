#include <stdio.h>
#include <string.h>

char x[110];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int start = -1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='1')
		{
			start = i;
			break;
		}
	}
	if(start==-1) printf("0");
	else
	{
		int count = 0;
		int control = 0;
		for(int i=a;i>=start+1;i--) if(x[i]=='1') control = 1;
		for(int i=a;i>=start;i-=2)
		{
			if(i>start) count++;
			else if(i==start) count += control;
			else break;
		}
		printf("%d",count);
	}
}