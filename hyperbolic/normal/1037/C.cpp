#include <stdio.h>
#define MAX 123456789
int a;
char x[1000010],y[1000010];
int check[1000010][5];
int func(int k, int type)
{
	if(k==a)
	{
		if(type==0)
		{
			if(x[k]==y[k]) return 0;
			else return 1;
		}
		else
		{
			if(x[k]!=y[k]) return 0;
			else return 1;
		}
	}
	if(check[k][type]!=-1) return check[k][type];
	if(type==0)
	{
		if(x[k]!=y[k])
		{
			int s1,s2;
			if(x[k+1]==y[k]) s1 = func(k+1,1)+1;
			else s1 = MAX;
			s2 = func(k+1,0)+1;
			return check[k][type] = s1<s2?s1:s2;
		}
		else return check[k][type] = func(k+1,0);
	}
	else
	{
		if(x[k]==y[k])
		{
			int s1,s2;
			if(x[k+1]==y[k]) s1 = func(k+1,1)+1;
			else s1 = MAX;
			s2 = func(k+1,0)+1;
			return check[k][type] = s1<s2?s1:s2;
		}
		else return check[k][type] = func(k+1,0);
	}
}

int main()
{
	scanf("%d",&a);
	scanf("%s%s",x+1,y+1);
	for(int i=0;i<=a;i++) check[i][0] = check[i][1] = -1;
	printf("%d",func(1,0));
}