#include <stdio.h>
#include <vector>

std::vector<long long int> V;
long long int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		
		long long int val = x[1];
		for(int i=2;i<=a;i++)
		{
			if(x[i]*x[i-1]<0)
			{
				V.push_back(val);
				val  = x[i];
			}
			else val = val>x[i]?val:x[i];
		}
		V.push_back(val);
		
		long long int ans = 0;
		for(int i=0;i<V.size();i++) ans += V[i];
		printf("%lld\n",ans);
	}
}