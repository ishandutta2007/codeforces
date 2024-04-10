#include <stdio.h>

char x[3][200010];
int value[3][200010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s%s",x[1]+1,x[2]+1);
	x[1][a+1] = x[2][a+1] = '0';
	
	int p = -1;
	for(int i=a;i>=1;i--)
	{
		
		if(p==-1) value[1][i] = x[1][i]-'0';
		else
		{
			if(x[1][p]=='1')
			{
				if(x[2][p]=='0') value[1][i] = value[1][p] + (x[1][i]-'0');
				else if(x[1][p+1]=='0') value[1][i] = (value[1][p]>value[2][p]+1?value[1][p]:value[2][p]+1)+(x[1][i]-'0');
				else value[1][i] = (value[1][p]>value[2][p+1]+2?value[1][p]:value[2][p+1]+2)+(x[1][i]-'0');
			}
			else
			{
				if(x[1][p+1]=='1')
				{
					if(x[2][p+1]=='1') value[1][i] = (value[1][p+1]>value[2][p+1]+1?value[1][p+1]:value[2][p+1]+1)+(x[1][i]-'0');
					else value[1][i] = (value[2][p+1]+1>value[1][p+1]?value[2][p+1]+1:value[1][p+1])+(x[1][i]-'0');
				}
				else value[1][i] = (value[1][p]>value[2][p]?value[1][p]:value[2][p]) + (x[1][i]-'0');
			}
		}
		
		if(p==-1) value[2][i] = x[2][i]-'0';
		else
		{
			if(x[2][p]=='1')
			{
				if(x[1][p]=='0') value[2][i] = value[2][p] + (x[2][i]-'0');
				else if(x[2][p+1]=='0') value[2][i] = (value[2][p]>value[1][p]+1?value[2][p]:value[1][p]+1)+(x[2][i]-'0');
				else value[2][i] = (value[2][p]>value[1][p+1]+2?value[2][p]:value[1][p+1]+2)+(x[2][i]-'0');
			}
			else
			{
				if(x[2][p+1]=='1')
				{
					if(x[1][p+1]=='1') value[2][i] = (value[2][p+1]>value[1][p+1]+1?value[2][p+1]:value[1][p+1]+1)+(x[2][i]-'0');
					else value[2][i] = (value[1][p+1]+1>value[2][p+1]?value[1][p+1]+1:value[2][p+1])+(x[2][i]-'0');
				}
				else value[2][i] = (value[1][p]>value[2][p]?value[1][p]:value[2][p]) + (x[2][i]-'0');
			}
		}
		
		if(x[1][i]=='1' || x[2][i]=='1') p = i;
	}
	
	if(x[2][1]=='0') printf("%d",value[1][1]);
	else
	{
		if(x[1][2]=='0')
		{
			int val1 = value[1][1];
			int val2 = value[2][1];
			printf("%d",val1>val2?val1:val2);
		}
		else
		{
			int val1 = value[1][2];
			int val2 = value[2][2]+1;
			printf("%d",val1>val2?val1:val2);
		}
	}
}