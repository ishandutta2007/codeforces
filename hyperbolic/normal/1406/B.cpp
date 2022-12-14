#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> V1,V2;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b>=0) V1.push_back(b);
			else V2.push_back(b);
		}
		if(!V1.empty()) std::sort(V1.begin(),V1.end());
		if(!V2.empty()) std::sort(V2.begin(),V2.end());
		if(V1.size()==0)
		{
			long long int ans = 1;
			for(int i=V2.size()-5;i<=V2.size()-1;i++) ans *= V2[i];
			printf("%lld\n",ans);
		}
		else
		{
			if(a==5)
			{
				long long int ans = 1;
				for(int i=0;i<V1.size();i++) ans *= V1[i];
				for(int i=0;i<V2.size();i++) ans *= V2[i];
				printf("%lld\n",ans);
				continue;
			}
			
			long long int ans = 0;
			if(V1.size()>=1&&V2.size()>=4)
			{
				long long int s = 1;
				s *= V1.back();
				for(int i=0;i<=3;i++) s *= V2[i];
				ans = ans>s?ans:s;
			}
			if(V1.size()>=3&&V2.size()>=2)
			{
				long long int s = 1;
				for(int i=V1.size()-3;i<=V1.size()-1;i++) s *= V1[i];
				for(int i=0;i<=1;i++) s *= V2[i];
				ans = ans>s?ans:s;
			}
			if(V1.size()>=5)
			{
				long long int s = 1;
				for(int i=V1.size()-5;i<=V1.size()-1;i++) s *= V1[i];
				ans = ans>s?ans:s;
			}
			printf("%lld\n",ans);
		}
	}
}