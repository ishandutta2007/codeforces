#include <stdio.h>
#include <vector>

std::vector< std::pair<int,long long int> > V1,V2;
int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		
		int a,b,c;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		scanf("%d",&c);
		for(int j=1;j<=c;j++) scanf("%d",&y[j]);
		
		for(int i=1;i<=a;i++)
		{
			int C = 1;
			while(x[i]%b==0) C*=b, x[i]/=b;
			if(V1.empty()) V1.push_back(std::make_pair(x[i],C));
			else if(V1.back().first==x[i]) V1[V1.size()-1].second += C;
			else V1.push_back(std::make_pair(x[i],C));
		}
		for(int i=1;i<=c;i++)
		{
			int C = 1;
			while(y[i]%b==0) C*=b, y[i]/=b;
			if(V2.empty()) V2.push_back(std::make_pair(y[i],C));
			else if(V2.back().first==y[i]) V2[V2.size()-1].second += C;
			else V2.push_back(std::make_pair(y[i],C));
		}
		
		
		if(V1.size()!=V2.size()) printf("No\n");
		else
		{
			for(int i=0;i<V1.size();i++)
			{
				if(V1[i].first!=V2[i].first || V1[i].second!=V2[i].second)
				{
					printf("No\n");
					goto u;
				}
			}
			printf("Yes\n");
			u:;
		}
	}
}