#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

int check[310][310];
int count[100010];
std::vector<int> index;
std::map<int,int> hash;

std::vector<int> V[100010];
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		index.clear();
		hash.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[i][j] = 0;
		for(int i=0;i<=a*b;i++) count[i] = 0;
		
		for(int i=1;i<=a*b;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a*b;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		int n = index.size();
		for(int i=1;i<=a*b;i++) count[hash[x[i]]]++;
		for(int i=1;i<=n;i++) count[i] += count[i-1];
		for(int i=1;i<=n;i++)
		{
			int L = count[i-1]+1, R = count[i];
			int p1 = ((L-1)/b)*b, p2 = (R/b)*b;
			for(int j=p1+b;;j+=b)
			{
				int M = (j<R?j:R);
				int m = (j-b+1>L?j-b+1:L);
				if(m>M) break;
				for(int k=M;k>=m;k--) V[i].push_back(k);
			}
			std::reverse(V[i].begin(),V[i].end());
		}
		
		int ans = 0;
		for(int i=1;i<=a*b;i++)
		{
			int val = V[hash[x[i]]].back();
			V[hash[x[i]]].pop_back();
		
			int s = (val-1)/b + 1;
			int t = val - ((s-1)*b);
			for(int j=1;j<t;j++) ans += check[s][j];
			check[s][t] = 1;
		}
		
		printf("%d\n",ans);
	}
}