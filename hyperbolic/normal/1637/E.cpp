#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

int x[300010],count[300010];
std::vector<int> V[1010],V2,index;
std::map<int,int> hash;
std::map< std::pair<int,int> , int> M;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		hash.clear();
		index.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=0;i<=a;i++) count[i] = 0;
		
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i;
		
		for(int i=1;i<=a;i++) count[hash[x[i]]]++;
		
		int SIZE = (int)sqrt(a+1);
		for(int i=0;i<=SIZE;i++) V[i].clear();
		V2.clear();
		
		for(int i=0;i<index.size();i++)
		{
			
			if(count[i]<=SIZE) V[count[i]].push_back(index[i]);
			else V2.push_back(index[i]);
		}
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			M[std::make_pair(c,d)] = M[std::make_pair(d,c)] = 1;
		}
		
		for(int i=0;i<=SIZE;i++) std::sort(V[i].begin(),V[i].end());
		for(int i=0;i<=SIZE;i++) std::reverse(V[i].begin(),V[i].end());
		
		long long int ans = 0;
		for(int i=0;i<=SIZE;i++)
		{
			for(int s=0;s<V[i].size();s++)
			{
				for(int j=i;j<=SIZE;j++)
				{
					for(int t=0;t<V[j].size();t++)
					{
						if(V[i][s]==V[j][t]) continue;
						if(M.find(std::make_pair(V[i][s],V[j][t]))==M.end())
						{
							long long int val = (long long int)(i+j)*(V[i][s]+V[j][t]);
							ans = ans>val?ans:val;
							goto u;
						}
					}
					u:;
				}
			}
		}
		
		for(int i=0;i<V2.size();i++)
		{
			for(int j=0;j<index.size();j++)
			{
				if(V2[i]==index[j]) continue;
				if(M.find(std::make_pair(V2[i],index[j]))==M.end())
				{
					long long int val = (long long int)(count[hash[V2[i]]]+count[j])*(V2[i]+index[j]);
					ans = ans>val?ans:val;
				}
			}
		}
		printf("%lld\n",ans);
	}
}