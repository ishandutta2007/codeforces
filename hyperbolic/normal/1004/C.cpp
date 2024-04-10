#include <stdio.h>
#include <set>

std::set<int> S,T;
int x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		S.insert(x[i]);
		y[i] = S.size();
	}
	
	long long int ans = 0 ;
	for(int i=a;i>=2;i--)
	{
		if(T.find(x[i])==T.end())
		{
			ans += y[i-1];
			T.insert(x[i]);
		}
	}
	printf("%lld",ans);
}