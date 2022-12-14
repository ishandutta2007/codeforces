#include <stdio.h>
#include <vector>
#define MOD 1000000007
std::vector< std::vector<long long int> > M[40010];
 
 
long long int count[10],count2[10];
int main()
{
	for(int i=1;i<=40000;i++) M[i].resize(10);
	for(int j=1;j<=40000;j++) for(int i=0;i<=9;i++) M[j][i].resize(10);
	
	M[1][0][9] = 1;
	M[1][1][9] = 1;
	for(int i=1;i<=9;i++) M[1][i][i-1] = 1;
	
	for(int ind=2;ind<=40000;ind++)
	{
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			{
				for(int k=0;k<=9;k++)
				{
					M[ind][i][j] += M[ind-1][i][k]*M[1][k][j];
					M[ind][i][j] %= MOD;
				}
			}
		}
	}
 
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=9;i++) count[i] = 0;
		
		int a,b;
		scanf("%d%d",&a,&b);
		while(a)
		{
			count[a%10]++;
			a/=10;
		}
		
		while(b)
		{
			if(b>=40000)
			{
				for(int i=0;i<=9;i++) count2[i] = 0;
				for(int i=0;i<=9;i++)
				{
					for(int j=0;j<=9;j++) count2[i] += (M[40000][i][j] * count[j]), count2[i] %= MOD;
				}
				for(int i=0;i<=9;i++) count[i] = count2[i];
				b-=40000;
			}
			else
			{
				for(int i=0;i<=9;i++) count2[i] = 0;
				for(int i=0;i<=9;i++)
				{
					for(int j=0;j<=9;j++) count2[i] += (M[b][i][j] * count[j]), count2[i] %= MOD;
				}
				for(int i=0;i<=9;i++) count[i] = count2[i];
				b = 0;
			}
		}
		
		long long int ans = 0;
		for(int i=0;i<=9;i++) ans += count[i], ans %= MOD;
		printf("%lld\n",ans);
	}
}