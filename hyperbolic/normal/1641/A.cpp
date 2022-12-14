#include <stdio.h>
#include <map>
#include <algorithm>

long long int x[200010];
std::map<long long int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=a;i++)
		{
			if(M[x[i]]>0) M[x[i]]--;
			else M[x[i]*b]++;
		}
		
		int ans = 0;
		for(std::map<long long int,int> ::iterator it = M.begin();it!=M.end();it++) ans += (it->second);
		printf("%d\n",ans);
	}
}