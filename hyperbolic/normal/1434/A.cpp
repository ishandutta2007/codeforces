#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

std::multiset<int> S[100010],T;
int x[10];
std::vector< std::pair<int,int> > V;
int main()
{
	for(int i=1;i<=6;i++) scanf("%d",&x[i]);
	int a;
	scanf("%d",&a);
	if(a==1)
	{
		printf("0");
		return 0;
	}
	
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=6;j++)
		{
			int t = b-x[j];
			S[i].insert(t);
			V.push_back(std::make_pair(t,i));
		}
	}
	
	std::multiset<int> ::iterator it,it2;
	for(int i=1;i<=a;i++)
	{
		it = S[i].begin();
		T.insert((*it));
	}
	std::sort(V.begin(),V.end());
	it = T.end();
	it--;
	int ans = (*it);
	//printf("%d!!\n",ans);
	for(int i=0;i<V.size();i++)
	{
		it = T.end();
		it--;
		ans = ans<(*it)-V[i].first?ans:(*it)-V[i].first;
		//printf("%d %d!!\n",(*it),V[i].first);
		it = S[V[i].second].begin();
		it2 = T.find((*it));
		T.erase(it2);
		it = S[V[i].second].find(V[i].first);
		S[V[i].second].erase(it);
		if(S[V[i].second].empty()) break;
		it = S[V[i].second].begin();
		T.insert(*it);
	}
	printf("%d",ans);
}