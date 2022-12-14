#include <stdio.h>
#include <map>
int x[100010];
std::map<int,int> check;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		check.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int t = 1;
			int s = 0;
			for(int j=0;j<=30;j++)
			{
				if(t<=x[i]) s = t;
				t*=2;
			}
			ans += check[s];
			check[s]++;
		}
		printf("%lld\n",ans);
	}
}