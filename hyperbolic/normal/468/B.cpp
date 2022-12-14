#include <stdio.h>
#include <vector>
#include <map>
 
std::map<int,int> M;
std::vector< std::pair<int,int> > V[100010];
int control = 0;
int ans[100010];
int p1 = -1,p2 = -1;
int func(int k, int prev, int len, int col, int C)
{
	if(prev!=0&&V[k].size()==1)
	{
		if(len%2==1)
		{
			if(k==p1||k==p2)
			{
				ans[k] = col;
				return 1;
			}
			else if(C==1)
			{
				ans[k] = 1-col;
				return 2;
			}
			else
			{
				control = 1;
				return 1;
			}
		}
		else ans[k] = col;
		return 1;
	}
	if(ans[k]!=-1) return 1;
	
	ans[k] = col;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		int D = func(V[k][i].first,k,len+1,col,C);
		if(D==2) ans[k] = 1-ans[k];
		return D;
	}
}
 
int x[100010];
 
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) M[x[i]] = i;
	
	for(int i=1;i<=a;i++)
	{
		if(M[b-x[i]]>=i)
		{
			if(M[b-x[i]]==i)
			{
				p1 = i;
				goto u;
			}
			else
			{
				V[M[b-x[i]]].push_back(std::make_pair(i,0));
				V[i].push_back(std::make_pair(M[b-x[i]],0));
			}
		}
		u:;
		if(M[c-x[i]]>=i)
		{
			if(M[c-x[i]]==i)
			{
				p2 = i;
				continue;
			}
			else
			{
				V[M[c-x[i]]].push_back(std::make_pair(i,1));
				V[i].push_back(std::make_pair(M[c-x[i]],1));
			}
		}
	}
	
	for(int i=1;i<=a;i++) ans[i] = -1;
	for(int i=1;i<=a;i++)
	{
		if(V[i].size()==1&&ans[i]==-1)
		{
			if(i==p1||i==p2) func(i,0,1,V[i][0].second,1);
			else func(i,0,1,V[i][0].second,0);
		}
	}
	if(control)
	{
		printf("NO");
		return 0;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(ans[i]==-1)
		{
			if(V[i].size()==2) ans[i] = 0;
			else
			{
				if(i==p1) ans[i] = 0;
				else if(i==p2) ans[i] = 1;
				else
				{
					printf("NO");
					return 0;
				}
			}
		}
	}
	
	printf("YES\n");
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}