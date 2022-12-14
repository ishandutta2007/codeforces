#include <stdio.h>
char x[1010];
int ans1,ans2;
int func(int k)
{
	int check = 0;
	for(int i=k;;i++)
	{
		if(x[i]=='_')
		{
			ans2+=check;
			check = 0;
		}
		else if(x[i]==')')
		{
			ans2+=check;
			return i;
		}
		else check = 1;
	}
}
int main()
{
	int a;
	int count = 0;
	scanf("%d%s",&a,x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='_') count = 0;
		else if(x[i]=='(')
		{
			i = func(i+1);
			if(i>a) break;
			count = 0;
		}
		else
		{
			count++;
			ans1 = ans1>count?ans1:count;
		}
	}
	printf("%d %d",ans1,ans2);
}