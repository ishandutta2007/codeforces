#include <stdio.h>
#include <vector>
#include <queue>

std::vector< std::pair<int,int> > ans;
std::priority_queue< std::pair<int,int> > Q;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		while(!Q.empty()) Q.pop();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b>=1) Q.push({b,i});
		}
		
		while(Q.size()>=2)
		{
			std::pair<int,int> A,B;
			A = Q.top();
			Q.pop();
			B = Q.top();
			Q.pop();
			
			ans.push_back(std::make_pair(A.second,B.second));
			if(A.first>=2) Q.push(std::make_pair(A.first-1,A.second));
			if(B.first>=2) Q.push(std::make_pair(B.first-1,B.second));
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}
}