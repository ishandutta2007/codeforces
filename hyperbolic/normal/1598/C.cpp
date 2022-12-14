#include <stdio.h>
#include <map>

int x[200010];
std::map<long long int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		
		if((2*sum)%a!=0)
		{
			printf("0\n");
			continue;
		}
		sum *= 2, sum /= a;
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			ans += M[sum-x[i]];
			M[x[i]]++;
		}
		
		printf("%lld\n",ans);
	}
}