#include <stdio.h>
#include <string.h>

char x[1010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int s = 1, t = 1;
	for(int i=1;i<=a;i++)
	{
		if(s>4) s = 1;
		if(t>4) t = 1;
		if(x[i]=='0')
		{
			printf("3 %d\n",t);
			t++;
		}
		else
		{
			printf("1 %d\n",s);
			s+=2;
		}
	}
}