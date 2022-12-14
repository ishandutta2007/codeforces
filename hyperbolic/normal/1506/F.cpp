#include <stdio.h>
#include <vector>
#include <algorithm>

int x[200010],y[200010];
std::pair<int,int> z[200010];
bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	if(A.first==B.first) return A.second<B.second;
	return A.first<B.first;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) z[i] = {x[i]-y[i],x[i]};
		std::sort(z+1,z+a+1,cmp);
		
		long long int ans = 0;
		z[0] = {0,1};
		for(int i=1;i<=a;i++)
		{
			if(z[i-1].first/2 != z[i].first/2) ans += (z[i].first/2 - z[i-1].first/2);
			else
			{
				if(z[i-1].first==z[i].first && z[i].first%2==0) ans += (z[i].second-z[i-1].second);
			}
		}
		printf("%lld\n",ans);
	}
}