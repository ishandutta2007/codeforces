#include <stdio.h>
#include <algorithm>
#include <map>

int x[200010];
std::map<int,int> M;

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
		for(int i=1;i<=a;i++) x[i] -= i;
		for(int i=1;i<=a;i++) M[x[i]]++;
		
		long long int ans = 0;
		for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++)
		{
			int c = (it->second);
			ans += (long long int)c*(c-1)/2;
		}
		printf("%lld\n",ans);
	}
}