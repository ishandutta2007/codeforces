#include <stdio.h>
#include <queue>
#include <algorithm>


std::priority_queue<int, std::vector<int>, std::greater<int> > Q1;
char x[1000010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		while(!Q1.empty()) Q1.pop();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int p = 1;
		long long int S1 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='*')
			{
				S1 += i-p;
				Q1.push(i-p);
				p++;
			}
		}
		
		long long int ans = S1;
		int limit = 0,c = 0;
		
		for(int i=2;i<=a;i++)
		{
			while(!Q1.empty())
			{
				if(Q1.top()<=limit)
				{
					c++;
					Q1.pop();
				}
				else break;
			}
			limit++;
			S1 -= Q1.size();
			S1 += c;
			ans = ans<S1?ans:S1;
		}
		printf("%lld\n",ans);
	}
}