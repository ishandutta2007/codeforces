#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V,temp;
int edge[1010][1010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) V.push_back(std::make_pair(i,i));
	
	int C = 1;
	while(V.size()>1)
	{
		temp.clear();
		int s = 0;
		while(s<V.size())
		{
			int t = s+b-1;
			t = t<V.size()-1?t:V.size()-1;
			// s~t
			for(int i=s;i<=t;i++)
			{
				for(int j=i+1;j<=t;j++)
				{
					for(int k1=V[i].first;k1<=V[i].second;k1++)
					{
						for(int k2=V[j].first;k2<=V[j].second;k2++)
						{
							edge[k1][k2] = C;
						}
					}
				}
			}
			temp.push_back(std::make_pair(V[s].first,V[t].second));
			s = t+1;
		}
		V.clear();
		for(int i=0;i<temp.size();i++) V.push_back(temp[i]);
		C++;
	}
	
	printf("%d\n",C-1);
	for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) printf("%d ",edge[i][j]);
}