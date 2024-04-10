#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#define MOD 998244353

std::vector<int> V[1010];
std::map<long long int, long long int> M[1010];
int x[1010],count[1010];
std::queue<int> Q;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<=a;i++) M[i].clear();
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) if(x[i]>0) M[i][0] = x[i];
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			count[d]++;
		}
		
		int control = 0;
		for(int i=1;i<=a;i++) if(x[i]>0) control = 1;
		if(control==0)
		{
			printf("0\n");
			continue;
		}
		
		int last = 0;
		for(int i=1;i<=a;i++) if(count[i]==0) Q.push(i);
		
		while(!Q.empty())
		{
			int k = Q.front();
			Q.pop();
			last = k;
			
			for(std::map<long long int,long long int> ::iterator it3 = M[k].begin();it3 != M[k].end();it3++)
			{
				std::pair<long long int,long long int> P = *(it3);
				P.first++;
				
				for(int i=0;i<V[k].size();i++)
				{
					int t = V[k][i];
					M[t][P.first] += P.second;
					if(M[t][P.first]>=2*MOD) M[t][P.first] = MOD + (M[t][P.first]-MOD)%MOD;
					
					std::map<long long int,long long int> ::iterator it = M[t].find(P.first);
					if(it!=M[t].begin())
					{
						it--;
						long long int val = it->first;
						if((it->first)+(it->second) >= P.first)
						{
							M[t][val] += M[t][P.first];
							if(M[t][val]>=2*MOD) M[t][val] = MOD + (M[t][val]-MOD)%MOD;
							M[t].erase(P.first);
							it = M[t].find(val);
						}
						else it++;
					}
					
					while(it!=M[t].end())
					{
						long long int val = it->first;
						std::map<long long int,long long int> ::iterator it2 = it;
						it2++;
						if(it2==M[t].end()) break;
						
						if((it->first)+(it->second) >= (it2->first))
						{
							M[t][val] += (it2->second);
							if(M[t][val]>=2*MOD) M[t][val] = MOD + (M[t][val]-MOD)%MOD;
							M[t].erase(it2);
							it = M[t].find(val);
						}
						else break;
					}
				}
			}
			
			for(int i=0;i<V[k].size();i++)
			{
				count[V[k][i]]--;
				if(count[V[k][i]]==0) Q.push(V[k][i]);
			}
		}
		
		std::map<long long int,long long int> ::iterator it = M[last].end();
		it--;
		printf("%lld\n",((it->first)+(it->second))%MOD);
	}
}