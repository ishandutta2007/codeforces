#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[3100010];
std::vector<int> W,save;

int func(int k, int limit)
{
	int ans = -1;
	int min = 0, max = V[k].size()-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[k][h]<=limit)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	return ans+1;
}

int next[3100010][2];
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int C = 1;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			x[i] = b;
			
			W.clear();
			for(int j=0;j<=30;j++) W.push_back(b%2), b/=2;
			std::reverse(W.begin(),W.end());
			
			int p = 0;
			for(int j=0;j<W.size();j++)
			{
				if(next[p][W[j]]==0) next[p][W[j]] = C++;
				p = next[p][W[j]];
				V[p].push_back(i);
			}
		}
		for(int i=1;i<C;i++) std::sort(V[i].begin(),V[i].end());
		
		int b;
		scanf("%d",&b);
		while(b--)
		{
			int L,R;
			scanf("%d%d",&L,&R);
			
			int val = 0;
			int p = 0;
			int ans = (1<<31)-1;
			for(int j=30;j>=0;j--)
			{
				int t = next[p][0];
				if(t==0)
				{
					val += (1<<j);
					p = next[p][1];
				}
				else
				{
					int P1 = func(t,R);
					int P2 = func(t,L-1);
					int val2 = P1 - P2;
					if(val2>=2) p = t;
					else if(val2==1)
					{
						save.push_back(x[V[t][P1-1]]);
						val += (1<<j);
						p = next[p][1];
					}
					else
					{
						val += (1<<j);
						p = next[p][1];
					}
				}
				if(p==0) goto u;
			}
			ans = val;
			u:;
			for(int i=0;i<save.size();i++) for(int j=i+1;j<save.size();j++) ans = ans<(save[i]|save[j])?ans:(save[i]|save[j]);
			printf("%d\n",ans);
			save.clear();
		}
		
		for(int i=0;i<C;i++) next[i][0] = next[i][1] = 0;
		for(int i=0;i<C;i++) V[i].clear();
	}
}