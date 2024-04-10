#include <stdio.h>
#include <vector>
#include <algorithm>

std::pair<int,int> P[110];
int check[210];
std::vector<int> V;
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=2*a;i++) check[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			check[c] = check[d] = 1;
			if(c>d)
			{
				int temp = c;
				c = d;
				d = temp;
			}
			P[i] = std::make_pair(c,d);
		}
		for(int i=1;i<=2*a;i++) if(check[i]==0) V.push_back(i);
		int s = V.size();
		for(int i=0;i<s/2;i++) P[b+1+i] = std::make_pair(V[i],V[i+s/2]);
		
		std::sort(P+1,P+a+1);
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++) if(P[i].second>= P[j].first && P[i].second<=P[j].second) ans++;
		}
		printf("%d\n",ans);
	}
}