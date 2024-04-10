#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

std::map<long long int,int> ans;
void func(std::vector<int> &V)
{
	if(V.empty()) return;
	long long int sum = 0;
	for(int i=0;i<V.size();i++) sum += V[i];
	ans[sum] = 1;
	int h = (V[0]+V.back())/2;
	
	std::vector<int> V1,V2;
	for(int i=0;i<V.size();i++)
	{
		if(V[i]<=h) V1.push_back(V[i]);
		else V2.push_back(V[i]);
	}
	if(V1.size()<V.size()) func(V1);
	if(V2.size()<V.size()) func(V2);
}

std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		ans.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			V.push_back(c);
		}
		std::sort(V.begin(),V.end());
		func(V);
		
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			printf("%s\n",ans[c]==1?"Yes":"No");
		}
	}
}