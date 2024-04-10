#include <stdio.h>
#include <vector>

std::vector< std::pair<long long int, long long int > > V1,V2;
int x[200010];
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
		x[0] = x[a+1] = 0;
		
		int control = 0;
		long long int val,limit;
		int p = b-1;
		val = limit = 0;
		while(p>=0)
		{
			val += x[p];
			limit = limit<val?limit:val;
			if(val>=0||p==0)
			{
				V1.push_back(std::make_pair(limit,val));
				limit = val = 0;
			}
			p--;
		}
		p = b+1;
		val = limit = 0;
		while(p<=a+1)
		{
			val += x[p];
			limit = limit<val?limit:val;
			if(val>=0||p==a+1)
			{
				V2.push_back(std::make_pair(limit,val));
				limit = val = 0;
			}
			p++;
		}
		
		val = x[b];
		int s = 0, t = 0;
		while(1)
		{
			if(val+V1[s].first>=0) val+=V1[s].second, s++;
			else if(val+V2[t].first>=0) val+=V2[t].second, t++;
			else
			{
				printf("NO\n");
				break;
			}	
			if(s>=V1.size()||t>=V2.size())
			{
				printf("YES\n");
				break;
			}
		}
	}
}