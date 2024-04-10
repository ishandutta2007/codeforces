#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

std::deque<int> D;
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) D.push_back(x[i]);
		while(!D.empty()&&D.front()=='0') D.pop_front();
		while(!D.empty()&&D.back()=='0') D.pop_back();
		
		if(D.empty()) printf("0\n");
		else
		{
			int s = 0;
			D.pop_front();
			
			std::vector<int> V;
			while(!D.empty())
			{
				if(D.front()=='1')
				{
					V.push_back(s);
					s = 0;
				}
				else s++;
				D.pop_front();
			}
			
			int ans = 12345678;
			int min = 0, max = V.size()+1;
			while(min<=max)
			{
				int h = (min+max)/2;
				int sum = 0;
				int val = 12345678;
				int C = V.size()-(h+1);
				for(int i=0;i<=C;i++) sum += V[i];
				val = val<sum?val:sum;
				for(int i=C+1;i<V.size();i++)
				{
					sum += V[i];
					sum -= V[i-(C+1)];
					val = val<sum?val:sum;
				}
				if(val<h)
				{
					ans = ans<h?ans:h;
					max = h-1;
				}
				else
				{
					ans = ans<val?ans:val;
					min = h+1;
				}
			}
			printf("%d\n",ans);
		}
	}
}