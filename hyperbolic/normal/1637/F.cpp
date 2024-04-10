#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[200010];

int x[200010];
long long int ans = 0;
std::pair<int,int> func(int k, int prev)
{
	std::vector<int> temp;
	temp.push_back(0);
	temp.push_back(0);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		temp.push_back(func(V[k][i],k).first);
	}
	std::sort(temp.begin(),temp.end());
	std::reverse(temp.begin(),temp.end());
	
	if(temp[0]<x[k])
	{
		ans += (x[k]-temp[0]);
		temp[0] = x[k];
	}
	return std::make_pair(temp[0],temp[1]);	
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	if(a==2)
	{
		printf("%d",2*(x[1]>x[2]?x[1]:x[2]));
		return 0;
	}
	
	int root = 1;
	for(int i=2;i<=a;i++) if(x[root]<x[i]) root = i;
	int max = x[root];
	
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	if(V[root].size()==1) root = V[root][0];
	
	std::pair<int,int> P = func(root,0);
	if(P.first<max) ans += (max-P.first);
	if(P.second<max) ans += (max-P.second);
	
	printf("%lld",ans);
}