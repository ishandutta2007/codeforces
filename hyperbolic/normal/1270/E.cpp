#include <stdio.h>
#include <vector>

struct str{
	int first;
	int second;
	int index;
};
std::vector<str> V;
std::vector<int> count[3][3];

void func()
{
	for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) count[i][j].clear();
	
	for(int i=0;i<V.size();i++) count[(V[i].first+12345678)%2][(V[i].second+12345678)%2].push_back(V[i].index);
	
	if(count[0][0].size()+count[1][1].size()==0)
	{
		if(count[0][1].size()==0||count[1][0].size()==0)
		{
			for(int i=1;i<V.size();i++)
			{
				V[i].first -= V[0].first;
				V[i].second -= V[0].second;
			}
			V[0].first = 0;
			V[0].second = 0;
			for(int i=0;i<V.size();i++) V[i].first/=2, V[i].second/=2;
			func();
		}
		else
		{
			printf("%d\n",count[0][1].size());
			for(int i=0;i<count[0][1].size();i++) printf("%d ",count[0][1][i]);
			return;
		}
	}
	else if(count[0][1].size()+count[1][0].size()==0)
	{
		if(count[0][0].size()==0||count[1][1].size()==0)
		{
			for(int i=1;i<V.size();i++)
			{
				V[i].first -= V[0].first;
				V[i].second -= V[0].second;
			}
			V[0].first = 0;
			V[0].second = 0;
			for(int i=0;i<V.size();i++) V[i].first/=2, V[i].second/=2;
			func();
		}
		else
		{
			printf("%d\n",count[0][0].size());
			for(int i=0;i<count[0][0].size();i++) printf("%d ",count[0][0][i]);
			return;
		}
	}
	else
	{
		printf("%d\n",count[0][0].size()+count[1][1].size());
		for(int i=0;i<count[0][0].size();i++) printf("%d ",count[0][0][i]);
		for(int i=0;i<count[1][1].size();i++) printf("%d ",count[1][1][i]);
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V.push_back({b,c,i});
	}
	func();
}