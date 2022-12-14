#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int first;
	int second;
	int index;
};
bool operator<(str a, str b)
{
	return a.first<b.first;
}
std::vector<str> V1,V2,temp;

int x[300010];
char y[3];
int ans[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) ans[i] = -1;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++)
		{
			scanf("%s",y+1);
			if(y[1]=='L')
			{
				if(x[i]%2==1) V1.push_back({x[i],1,i});
				else V2.push_back({x[i],1,i});
			}
			else
			{
				if(x[i]%2==1) V1.push_back({x[i],2,i});
				else V2.push_back({x[i],2,i});
			}
		}
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		
		temp.clear();
		for(int i=0;i<V1.size();i++)
		{
			if(temp.size()==0) temp.push_back(V1[i]);
			else
			{
				if(V1[i].second==1)
				{
					if(temp.back().second==1)
					{
						ans[temp.back().index] = (V1[i].first+temp.back().first)/2;
						ans[V1[i].index] = (V1[i].first+temp.back().first)/2;
					}
					else
					{
						ans[temp.back().index] = (V1[i].first-temp.back().first)/2;
						ans[V1[i].index] = (V1[i].first-temp.back().first)/2;
					}
					temp.pop_back();
				}
				else temp.push_back(V1[i]);
			}
		}
		
		while(temp.size()>=2)
		{
			str A = temp.back();
			temp.pop_back();
			str B = temp.back();
			temp.pop_back();
			if(B.second==1)
			{
				ans[A.index] = (2*b-A.first+B.first)/2;
				ans[B.index] = (2*b-A.first+B.first)/2;
			}
			else
			{
				ans[A.index] = (2*b-A.first-B.first)/2;
				ans[B.index] = (2*b-A.first-B.first)/2;
			}
		}
		
		temp.clear();
		
		for(int i=0;i<V2.size();i++)
		{
			if(temp.size()==0) temp.push_back(V2[i]);
			else
			{
				if(V2[i].second==1)
				{
					if(temp.back().second==1)
					{
						ans[temp.back().index] = (V2[i].first+temp.back().first)/2;
						ans[V2[i].index] = (V2[i].first+temp.back().first)/2;
					}
					else
					{
						ans[temp.back().index] = (V2[i].first-temp.back().first)/2;
						ans[V2[i].index] = (V2[i].first-temp.back().first)/2;
					}
					temp.pop_back();
				}
				else temp.push_back(V2[i]);
			}
		}
		
		while(temp.size()>=2)
		{
			str A = temp.back();
			temp.pop_back();
			str B = temp.back();
			temp.pop_back();
			if(B.second==1)
			{
				ans[A.index] = (2*b-A.first+B.first)/2;
				ans[B.index] = (2*b-A.first+B.first)/2;
			}
			else
			{
				ans[A.index] = (2*b-A.first-B.first)/2;
				ans[B.index] = (2*b-A.first-B.first)/2;
			}
		}
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}