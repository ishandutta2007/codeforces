#include <stdio.h>
#include <vector>
#include <algorithm>

int x[100010];
long long int sum[100010],XOR[100010];

long long int func(int c, int d)
{
	return (sum[d]-sum[c-1]) - (XOR[d]^XOR[c-1]);
}
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) sum[i] = sum[i-1]+x[i];
		for(int i=1;i<=a;i++) XOR[i] = XOR[i-1]^x[i];
		
		V.clear();
		V.push_back(0);
		for(int i=1;i<=a;i++) if(x[i]>0) V.push_back(i);
		V.push_back(a+1);
		
		while(b--)
		{
			int c2,d2;
			scanf("%d%d",&c2,&d2);
			int min, max;
			int c,d;
			min = 0, max = V.size()-1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(V[h]>=c2)
				{
					c = h;
					max = h-1;
				}
				else min = h+1;
			}
			min = 0, max = V.size()-1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(V[h]<=d2)
				{
					d = h;
					min = h+1;
				}
				else max = h-1;
			}
			
			if(c>d)
			{
				printf("%d %d\n",c2,c2);
				continue;
			}
			
			long long int ans = func(V[c],V[d]);
			std::pair<int,int> P = std::make_pair(V[c],V[d]);
			
			for(int i=0;i<=50;i++)
			{
				for(int j=0;j<=50;j++)
				{
					if(c+i>=V.size() || d-j<0) continue;
					
					int L = V[c+i];
					int R = V[d-j];
					if(L<=R)
					{
						long long int val = func(L,R);
						if(ans==val && P.second-P.first+1 > R-L+1) P = std::make_pair(L,R);
					}
				}
			}
			printf("%d %d\n",P.first,P.second);
		}
	}
}