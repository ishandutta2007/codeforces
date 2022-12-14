#include <stdio.h>
#include <map>
#include <vector>

std::map<int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			M[c]++;
		}
		
		std::vector<int> V;
		for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++) if((it->second)>=b) V.push_back(it->first);
		
		if(V.size()==0) printf("-1\n");
		else
		{
			int l = V[0], r = V[0];
			int p = 0;
			while(p<V.size())
			{
				int last = p;
				for(int i=1;i+p<V.size();i++)
				{
					if(V[i+p]==V[p]+i) last = i+p;
					else break;
				}
				if(last-p > r-l) r = V[last], l = V[p];
				p = last+1;
			}
			printf("%d %d\n",l,r);
		}
	}
}