#include <stdio.h>
#include <string.h>

char x[100010];
int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a,s=0,t=0;
	scanf("%s",x+1);
	a = strlen(x+1);
	if(a%2==1)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='U') s++;
		if(x[i]=='D') s--;
		if(x[i]=='L') t--;
		if(x[i]=='R') t++;
	}
	printf("%d",(abs(s)+abs(t))/2);
}