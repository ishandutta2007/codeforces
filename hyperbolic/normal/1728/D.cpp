#include <stdio.h>
#include <string.h>

char x[2010];
int check[2010][2010];
int func(int L, int R) // win :1 draw:2 lose:3
{
	if(L>R) return 2;
	if(check[L][R]!=-1) return check[L][R];
	
	int val;
	int s1,s2,s3,ans=3;
	val = func(L+2,R);
	if(val==2)
	{
		if(x[L]>x[L+1]) s1 = 3;
		if(x[L]==x[L+1]) s1 = 2;
		if(x[L]<x[L+1]) s1 = 1;
	}
	else s1 = val;
	val = func(L+1,R-1);
	if(val==2)
	{
		if(x[L]>x[R]) s2 = 3;
		if(x[L]==x[R]) s2 = 2;
		if(x[L]<x[R]) s2 = 1;
	}
	else s2 = val;
	s3 = s1>s2?s1:s2;
	ans = ans<s3?ans:s3;
	
	val = func(L,R-2);
	if(val==2)
	{
		if(x[R]>x[R-1]) s1 = 3;
		if(x[R]==x[R-1]) s1 = 2;
		if(x[R]<x[R-1]) s1 = 1;
	}
	else s1 = val;
	val = func(L+1,R-1);
	if(val==2)
	{
		if(x[R]>x[L]) s2 = 3;
		if(x[R]==x[L]) s2 = 2;
		if(x[R]<x[L]) s2 = 1;
	}
	else s2 = val;
	s3 = s1>s2?s1:s2;
	ans = ans<s3?ans:s3;
	return check[L][R] = ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) check[i][j] = -1;
		
		int val = func(1,a);
		if(val==1) printf("Alice\n");
		else if(val==2) printf("Draw\n");
		else if(val==3) printf("Bob\n");
	}
}