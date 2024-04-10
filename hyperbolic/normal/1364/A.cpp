#include <stdio.h>
#include <vector>

std::vector<int> V[10010];
int abs(int k)
{
	return k>0?k:-k;
}

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=0;i<=b;i++) V[i].clear();
		int s = 0;
		V[0].push_back(0);
		for(int i=1;i<=a;i++) s += x[i], V[s%b].push_back(i);
		
		int ans = -1;
		for(int i=0;i<b;i++)
		{
			if(V[i].size()==0) continue;
			for(int j=i+1;j<b;j++)
			{
				if(V[j].size()==0) continue;
				int t = abs(V[i][0]-V[j][V[j].size()-1]);
				ans = ans>t?ans:t;
				t = abs(V[i][V[i].size()-1]-V[j][0]);
				ans = ans>t?ans:t;
			}
		}
		printf("%d\n",ans);
	}
}