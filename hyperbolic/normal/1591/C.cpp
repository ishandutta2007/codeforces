#include <stdio.h>
#include <vector>
#include <algorithm>

int x[200010];
std::vector<int> V1,V2;
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
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		for(int i=1;i<=a;i++) if(x[i]<0) V1.push_back(-x[i]);
		for(int i=1;i<=a;i++) if(x[i]>0) V2.push_back(x[i]);
		std::reverse(V2.begin(),V2.end());
		V1.push_back(0);
		V2.push_back(0);
		
		long long int ans1 = V1[0]>V2[0]?V1[0]:V2[0];
		long long int ans2 = 0;
		for(int i=0;i<V1.size();i+=b) ans2 += 2*V1[i];
		for(int i=0;i<V2.size();i+=b) ans2 += 2*V2[i];
		printf("%lld\n",ans2-ans1);
	}
}