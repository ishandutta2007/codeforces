#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int possible[1010],limit[1010];
char x[1010],y[1010];
int a,b;
int C;

/*
long long int func(int s, int t, int count)
{
	if(s>limit[t]) return 0;
	if(count>C) return 0;
	if(s>a)
	{
		if(count==C) return 1;
		else return 0;
	}
	if(check[s][t][count]!=-1) return check[s][t][count];
	
	long long int s1 = 0, s2 = 0;
	s1 = func(s+1,t,count);
	if(possible[s]) s2 = func(s+b,s+b-1,count+1);
	return check[s][t][count] = (s1+s2)%MOD;
}
*/

long long int DP[510][510],DP2[510][510];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",x+1,y+1);
		a = strlen(x+1);
		b = strlen(y+1);
		
		//for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) for(int k=0;k<=a;k++) check[i][j][k] = -1;
		for(int i=0;i<=a;i++) possible[i] = 0;
		for(int i=0;i<=a;i++) limit[i] = a+1;
		for(int i=a-b+1;i>=1;i--)
		{
			int control = 1;
			for(int j=1;j<=b;j++) if(y[j]!=x[i+j-1]) control = 0;
			if(control==1)
			{
				possible[i] = 1;
				for(int j=0;j<i;j++) limit[j] = i+b-1;
			}
		}
		
		int p = 1;
		C = 0;
		while(p<=a)
		{
			if(possible[p]==0) p++;
			else
			{
				C++;
				for(int j=p+b-1;j>=p;j--)
				{
					if(possible[j])
					{
						p = j+b;
						break;
					}
				}
			}
		}
		
		for(int s=1;s<=a+1;s++) for(int t=0;t<=a;t++) DP[s][t] = 0;
		for(int s=1;s<=a+1;s++) for(int t=0;t<s;t++) DP[s][t] = 1;
		for(int t=0;t<=a;t++)
		{
			int control = 0;
			if(a+1>limit[t]) for(int s=1;s<=a+1;s++) DP[s][t] = 0;
		}
		
		for(int count=C-1;count>=0;count--)
		{
			for(int s=1;s<=a+1;s++) for(int t=0;t<=a;t++) DP2[s][t] = DP[s][t];
			for(int s=1;s<=a+1;s++) for(int t=0;t<=a;t++) DP[s][t] = 0;
			for(int s=a-b+1;s>=1;s--)
			{
				for(int t=0;t<s;t++)
				{
					if(s>limit[t]) DP[s][t] = 0;
					else
					{
						if(possible[s]) DP[s][t] = DP[s+1][t] + DP2[s+b][s+b-1];
						else DP[s][t] = DP[s+1][t];
						DP[s][t]%=MOD;
					}
				}
			}
		}
		
		printf("%d %lld\n",C,DP[1][0]);
	}
}