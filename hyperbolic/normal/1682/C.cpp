#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

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
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			M[b]++;
		}
		
		int ans = 0;
		for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++)
		{
			if((it->second)>=2) ans+=2;
			else if((it->second)==1) ans++;
		}
		
		printf("%d\n",(ans+1)/2);
	}
}