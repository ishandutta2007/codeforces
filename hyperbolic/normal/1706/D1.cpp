#include <stdio.h>
#include <vector>
#include <algorithm>
#define SIZE 350

int sum[100010],x[100010],check[100010];
std::vector< std::pair<int,int> > V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		//for(int i=0;i<=100000;i++) sum[i] = 0;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			x[i] = c;
			sum[c]++;
		}
		//for(int i=1;i<=100000;i++) sum[i] += sum[i-1];
		if(x[a]<b)
		{
			printf("0\n");
			continue;
		}
		
		int ans = 12345678;
		for(int m=1;m<=SIZE;m++)
		{
			if(m>x[1]) break;
			int M = 0;
			for(int i=1;i<=a;i++)
			{
				int t = x[i]/m;
				t = t<b?t:b;
				int val = x[i]/t;
				M = M>val?M:val;
			}
			ans = ans<(M-m)?ans:(M-m);
		}
		
		for(int k=1;k<=SIZE&&k<=b;k++)
		{
			V.clear();
			int val = x[a]/k;
			int min = val, max = val;
			for(int i=1;i<=a-1;i++)
			{
				// min = val, max = val
				if(x[i]<val) min = min<x[i]?min:x[i];
				else if(x[i]/b>val) max = max<x[i]/b?max:x[i]/b;
				else
				{
					int t;
					t = x[i]/val;
					t = t<b?t:b;
					int S1 = x[i]/t;
					t = x[i]/(val+1);
					t++;
					t = t<b?t:b;
					int S2 = x[i]/t;
					//printf("%d : %d %d??\n",val,S2,S1);
					V.push_back(std::make_pair(S2,S1));
				}
			}
			V.push_back(std::make_pair(val,val));
			std::sort(V.begin(),V.end());
			std::reverse(V.begin(),V.end());
			
			check[V.size()] = val;
			for(int i=V.size()-1;i>=0;i--)
			{
				check[i] = check[i+1]>V[i].second?check[i+1]:V[i].second;
			}
			
			for(int i=0;i<V.size();i++)
			{
				int m = min<V[i].first?min:V[i].first;
				int M = max>check[i+1]?max:check[i+1];
				ans = ans<(M-m)?ans:(M-m);
			}
			int m = min;
			int M = max>check[0]?max:check[0];
			ans = ans<(M-m)?ans:(M-m);
		}
		
		printf("%d\n",ans);
	}
}