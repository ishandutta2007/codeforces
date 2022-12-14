#include <stdio.h>
#include <vector>
#define MIN -12345678
int a;
std::pair<int,int> P[110];
int min(int a, int b)
{
	return a<b?a:b;
}

int DP1[30010][110],DP2[30010][110];
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i] = std::make_pair(b,c);
	}
	
	int sum = 0;
	for(int i=1;i<=a;i++) sum += P[i].second;
	
	int A = 10000;
	for(int s=a;s>=1;s--)
	{
		for(int t=-sum;t<=20000;t++)
		{
			for(int k=1;k<=a;k++)
			{
				int score;
				if(t>0) score = min(t+2*P[s].first,P[s].second);
				else score = min(2*P[s].first,P[s].second-t);
				int s1 = DP2[A+t+2*P[s].first-P[s].second][k-1]+score;
				int s2 = DP2[A+t][k];
				DP1[A+t][k] = s1>s2?s1:s2;
			}
		}
		
		for(int t=-sum;t<=20000;t++)
		{
			for(int k=1;k<=a;k++)
			{
				DP2[A+t][k] = DP1[A+t][k];
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		int ans = DP2[A-sum][i];
		printf("%.12lf ",(double)ans/2);
	}
}