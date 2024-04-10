#include <stdio.h>
#include <vector>

int x[200010],y[200010],check[200010],next[200010];
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) next[x[i]] = y[i];
		
		int ans1 = 0, ans2 = 0;
		for(int i=1;i<=a;i++)
		{
			int p = i;
			V.clear();
			while(check[p]==0)
			{
				check[p] = 1;
				V.push_back(p);
				p = next[p];
			}
			int n = V.size();
			ans1 += n/2, ans2 += n/2;
		}
		
		long long int ans = 0;
		for(int i=a-ans2+1;i<=a;i++) ans += i;
		for(int i=1;i<=ans1;i++) ans -= i;
		ans*=2;
		printf("%lld\n",ans);
	}
}