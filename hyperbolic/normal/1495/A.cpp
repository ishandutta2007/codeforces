#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

std::vector<int> V1,V2;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=2*a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			if(b==0) V1.push_back(abs(c));
			else V2.push_back(abs(b));
		}
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		
		double ans = 0;
		for(int i=0;i<V1.size();i++)
		{
			long long int s = V1[i];
			long long int t = V2[i];
			//printf("%lld %lld??\n",s,t);
			ans += sqrt(s*s+t*t);
		}
		printf("%.12lf\n",ans);
	}
}