#include <stdio.h>
#include <set>
#include <vector>

std::vector<int> V[200010];
int next[200010][21],height[200010];

void init(int k, int p, int h)
{
	next[k][0] = p;
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		init(V[k][i],k,h+1);
	}
}

int find(int k, int h)
{
	for(int i=20;i>=0;i--)
	{
		if(h>=(1<<i))
		{
			k = next[k][i];
			h -= (1<<i);
		}
	}
	return k;
}

int LCA(int s, int t)
{
	if(height[s]>height[t]) s = find(s,height[s]-height[t]);
	if(height[s]<height[t]) t = find(t,height[t]-height[s]);
	
	for(int i=20;i>=0;i--)
	{
		if(next[s][i]!=next[t][i])
		{
			s = next[s][i];
			t = next[t][i];
		}
	}
	if(s!=t) return next[s][0];
	else return s;
}

std::set< std::pair<int,int> > S;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	init(1,0,1);
	for(int j=1;j<=20;j++) for(int i=1;i<=a;i++) next[i][j] = next[next[i][j-1]][j-1];
	
	int b;
	scanf("%d",&b);
	while(b--)
	{
		S.clear();
		int c;
		scanf("%d",&c);
		for(int i=1;i<=c;i++)
		{
			int d;
			scanf("%d",&d);
			S.insert(std::make_pair(a-height[d],d));
		}
		
		while(S.size()>1)
		{
			std::pair<int,int> P = *(S.begin());
			S.erase(P);
			std::pair<int,int> Q = *(S.begin());
			int s = P.second;
			int t = Q.second;
			if(P.first==Q.first)
			{
				int g = LCA(s,t);
				
				S.insert(std::make_pair(a-height[s],s));
				for(std::set< std::pair<int,int> > ::iterator it = S.begin();it!=S.end();it++)
				{
					int k = (it->second);
					if(height[k]<height[g])
					{
						printf("NO\n");
						goto u;
					}
					else
					{
						if(height[k]<=height[s] && find(k,height[k]-height[g])==g && find(s,height[s]-height[k])==k);
						else if(height[k]<=height[t] && find(k,height[k]-height[g])==g && find(t,height[t]-height[k])==k);
						else
						{
							printf("NO\n");
							goto u;
						}
					}
				}
				printf("YES\n");
				goto u;
			}
			else
			{
				s = find(s,height[s]-height[t]);
				S.insert(std::make_pair(a-height[s],s));
			}
		}
		printf("YES\n");
		u:;
	}
}