#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
std::vector<int> divisor[200010];
std::vector<int> save[200010];
int next[200010],size[200010],check[200010];
long long int count[200010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	for(int i=1;i<=200000;i++) for(int j=i;j<=200000;j+=i) divisor[j].push_back(i);
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=0;j<divisor[b].size();j++) save[divisor[b][j]].push_back(i);
	}
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	for(int i=1;i<=200000;i++)
	{
		for(int j=0;j<save[i].size();j++)
		{
			check[save[i][j]] = 1;
			next[save[i][j]] = save[i][j];
			size[save[i][j]] = 1;
		}
		
		for(int j=0;j<save[i].size();j++)
		{
			int s = save[i][j];
			for(int k=0;k<V[s].size();k++)
			{
				if(check[V[s][k]]==1)
				{
					int t = V[s][k];
					int s2 = find(s);
					int t2 = find(t);
					if(s2!=t2)
					{
						next[t2] = s2;
						size[s2] += size[t2];
					}
				}
			}
		}
		
		for(int j=0;j<save[i].size();j++)
		{
			int s = save[i][j];
			if(s==next[s]) count[i] += (long long int)size[s]*(size[s]+1)/2;
		}
		
		for(int j=0;j<save[i].size();j++)
		{
			check[save[i][j]] = 0;
			next[save[i][j]] = 0;
			size[save[i][j]] = 0;
		}
	}
	
	
	for(int i=200000;i>=1;i--) for(int j=2*i;j<=200000;j+=i) count[i] -= count[j];
	
	for(int i=1;i<=200000;i++) if(count[i]>0) printf("%d %lld\n",i,count[i]);
}