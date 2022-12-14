#include <stdio.h>
#include <string.h>

int a;
char x[200010];
int func(int k, int type, int s, int t)
{
	if(k>a) return 0;
	
	if(type==1)
	{
		if(x[k]==s+'0') return func(k+1,2,s,t)+1;
		else return func(k+1,1,s,t);
	}
	else
	{
		if(x[k]==t+'0') return func(k+1,1,s,t)+1;
		else return func(k+1,2,s,t);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		a = strlen(x+1);
		
		int ans = 0;
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			{
				int k = func(1,1,i,j);
				if(i!=j && k%2==1) k--;
				ans = ans>k?ans:k;
			}
		}
		printf("%d\n",a-ans);
	}
}