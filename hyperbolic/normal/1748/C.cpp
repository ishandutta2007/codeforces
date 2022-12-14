#include <stdio.h>
#include <map>
#include <vector>

int x[200010];
std::map<long long int,int> check;
std::vector<int> start;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		start.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		start.push_back(0);
		for(int i=1;i<=a;i++) if(x[i]==0) start.push_back(i);
		start.push_back(a+1);
		
		long long int S;
		S = 0;
		int ans = 0;
		for(int i=start[0];i<start[1];i++)
		{
			S += x[i];
			if(S==0) ans++;
		}
		
		for(int j=1;j+1<start.size();j++)
		{
			check.clear();
			int val = 0;
			S = 0;
			for(int i=start[j];i<start[j+1];i++)
			{
				S += x[i];
				check[S]++;
				int val2 = check[S];
				val = val>val2?val:val2;
			}
			ans += val;
		}
		printf("%d\n",ans-1);
	}
}