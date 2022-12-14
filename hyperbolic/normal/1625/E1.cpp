#include <stdio.h>
#include <vector>
char x[300010];
int sum[300010];

std::pair<int, long long int> next[300010][21];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='(') sum[i] = sum[i-1] + 1;
		else sum[i] = sum[i-1]-1;
	}
	
	next[a][0] = std::make_pair(a,0);
	next[a+1][0] = std::make_pair(a+1,0);
	for(int i=a-1;i>=1;i--)
	{
		if(x[i]=='(')
		{
			if(x[i+1]==')') next[i][0] = std::make_pair(i+2,0);
			else
			{
				int t = i+1;
				long long int s1 = 0, s2 = 0;
				while(t!=next[t][0].first)
				{
					s1++;
					s2 += next[t][0].second;
					t = next[t][0].first;
				}
				
				if(t==i+1) next[i][0] = std::make_pair(i,0);
				else if(x[t]=='(') next[i][0] = std::make_pair(i,0);
				else next[i][0] = std::make_pair(t+1,s1*(s1+1)/2 + s2);
			}
		}
		else next[i][0] = std::make_pair(i,0);
	}
	
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=a+1;i++)
		{
			next[i][j].first = next[next[i][j-1].first][j-1].first;
			next[i][j].second = next[i][j-1].second + next[next[i][j-1].first][j-1].second;
		}
	}
	
	while(b--)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		
		//printf("%d %d : %d %d !!\n",d,e,next[d][0].first,next[d][0].second);
		
		long long int s1 = 0, s2 = 0;
		for(int j=20;j>=0;j--)
		{
			if(next[d][j].first<=e)
			{
				s1 += (1<<j);
				s2 += next[d][j].second;
				d = next[d][j].first;
			}
		}
		s1++, s2 += next[d][0].second;
		printf("%lld\n",s1*(s1+1)/2 + s2);
	}
}