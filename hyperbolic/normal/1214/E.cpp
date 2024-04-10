#include <stdio.h>
#include <algorithm>
#include <vector>

bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	return A.first>B.first;
}


int x[100010];
std::pair<int,int> y[100010];
std::vector<int> V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i]=std::make_pair(x[i],i);
	std::sort(y+1,y+a+1,cmp);
	
	for(int i=1;i<=a;i++) V.push_back(2*y[i].second-1);
	for(int i=1;i<a;i++) printf("%d %d\n",V[i-1],V[i]);
	
	for(int i=1;i<=a;i++)
	{
		if(V.size()-i<y[i].first)
		{
			printf("%d %d\n",V[V.size()-1],2*y[i].second);
			V.push_back(2*y[i].second);
		}
		else
		{
			int p = V[i+y[i].first-2];
			printf("%d %d\n",p,2*y[i].second);
		}
	}
}