#include <stdio.h>
#include <map>
#include <queue>

int count[100010],sum[100010];
int x[100010];
std::map<int,int> M;
std::priority_queue<int> Q;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		while(!Q.empty()) Q.pop();
		
		M.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a;i++) count[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++)
		{
			if(x[i]<=a) count[x[i]]++;
			else M[x[i]]++;
		}
		
		sum[0] = (count[0]>0?1:0);
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + (count[i]>0?1:0);
		
		int C = 0, S = 0;
		int ans = 12345678;
		for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++)
		{
			Q.push(it->second);
			S += (it->second);
		}
		
		for(int i=a;i>=0;i--)
		{
			int s;
			if(i==0) s = 0;
			else s = i - sum[i-1];
			Q.push(count[i]);
			S += count[i];
			while(S>b)
			{
				int val = Q.top();
				S -= val;
				C++;
				Q.pop();
			}
			if(S>=s) ans = ans<C?ans:C;
			else if((b-S)>=(s-S)) ans = ans<C?ans:C;
		}
		
		printf("%d\n",ans);
	}
}