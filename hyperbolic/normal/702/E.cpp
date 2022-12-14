#include <stdio.h>
#include <vector>

std::pair<int, long long int> next1[100010][50],next2[100010][50];
long long int power[110];
int main()
{
	power[0] = 1;
	for(int i=1;i<=40;i++) power[i] = 2*power[i-1];
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=0;i<a;i++)
	{
		int c;
		scanf("%d",&c);
		next1[i][0].first = next2[i][0].first = c;
	}
	for(int i=0;i<a;i++)
	{
		int c;
		scanf("%d",&c);
		next1[i][0].second = next2[i][0].second = c;
	}
	
	for(int j=1;j<=40;j++)
	{
		for(int i=0;i<a;i++)
		{
			next1[i][j].first = next1[next1[i][j-1].first][j-1].first;
			next1[i][j].second = next1[next1[i][j-1].first][j-1].second + next1[i][j-1].second;
			next2[i][j].first = next2[next2[i][j-1].first][j-1].first;
			int s = next2[next2[i][j-1].first][j-1].second;
			int t = next2[i][j-1].second;
			next2[i][j].second = s<t?s:t;
		}
	}
	
	for(int i=0;i<a;i++)
	{
		long long int c = b;
		int p = i;
		long long int ans1 = 0, ans2 = 1234567890;
		for(int j=40;j>=0;j--)
		{
			if(power[j]<=c)
			{
				c -= power[j];
				ans1 += next1[p][j].second;
				ans2 = ans2<next2[p][j].second?ans2:next2[p][j].second;
				p = next1[p][j].first;
			}
		}
		printf("%lld %lld\n",ans1,ans2);
	}
}