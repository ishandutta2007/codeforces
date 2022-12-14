#include <stdio.h>
#include <vector>
#include <algorithm>


std::vector<int> ans,V;
int x[300010],y[300010];
int check[300010],count[300010];
void func(int k)
{
	if(check[k]) return;
	check[k] = 1;
	func(y[k]);
}

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		ans.clear();
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++) count[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) count[(x[i]-i+a)%a]++;
		for(int i=0;i<a;i++) if(count[i]>=a/3) V.push_back(i);
		
		for(int j=0;j<V.size();j++)
		{
			int t = V[j];
			for(int i=1;i<=a;i++) y[i] = (x[i]-t+a)%a;
			for(int i=1;i<=a;i++) if(y[i]==0) y[i] = a;
			
			for(int i=1;i<=a;i++) check[i] = 0;
			int C = 0;
			for(int i=1;i<=a;i++)
			{
				if(check[i]==0) C++;
				func(i);
			}
			if((a-C)<=b) ans.push_back((a-t)%a);
		}
		std::sort(ans.begin(),ans.end());
		
		printf("%d ",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
	}
}