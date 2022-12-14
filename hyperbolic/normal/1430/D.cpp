#include <stdio.h>
#include <vector>

char x[200010];
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int p = 1;
		x[a+1] = 0;
		for(int i=2;i<=a+1;i++)
		{
			if(x[i]!=x[i-1])
			{
				V.push_back(i-p-1);
				p = i;
			}
		}
		
		int pivot = 0;
		int ans = 0;
		for(int i=0;i<V.size();i++)
		{
			while(pivot<i) pivot++;
			while(pivot<V.size()&&V[pivot]==0) pivot++;
			if(pivot<V.size())
			{
				ans++;
				V[pivot]--;
			}
			else
			{
				ans++;
				V.pop_back();
			}
		}
		printf("%d\n",ans);
	}
}