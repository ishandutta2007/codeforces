#include <stdio.h>
#include <vector>

std::vector<int> V,V2;
std::vector< std::pair<int,int> > ans;
std::vector<int> ans2;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		ans2.clear();
		V.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V.push_back(b);
		}
		
		int S = 1;
		while(V.size()>=1)
		{
			for(int i=1;i<V.size();i++)
			{
				if(V[i]==V[0])
				{
					for(int j=1;j<i;j++) ans.push_back(std::make_pair(S+i+j-1,V[j]));
					ans2.push_back(2*i);
					S += (2*i);
					
					V2.clear();
					for(int j=i-1;j>=1;j--) V2.push_back(V[j]);
					for(int j=i+1;j<V.size();j++) V2.push_back(V[j]);
					V = V2;
					goto u;
				}
			}
			break;
			u:;
		}
		
		if(V.size()>0) printf("-1\n");
		else
		{
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
			printf("%d\n",ans2.size());
			for(int i=0;i<ans2.size();i++) printf("%d ",ans2[i]);
			printf("\n");
		}
		
	}
}