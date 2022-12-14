#include <stdio.h>
#include <vector>

std::vector<int> V[250010];
int prev[250010],height[250010];
void func(int k, int p, int h)
{
	if(height[k]>0) return;
	prev[k] = p;
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		func(V[k][i],k,h+1);
	}
}

std::vector<int> count[250010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
	}
	
	int d = (a-1)/c+1;
	func(1,0,1);
	for(int i=1;i<=a;i++)
	{
		if(height[i]>=d)
		{
			printf("PATH\n");
			printf("%d\n",height[i]);
			int v = i;
			while(v)
			{
				printf("%d ",v);
				v = prev[v];
			}
			return 0;
		}
		else count[height[i]].push_back(i);
	}
	
	printf("CYCLES\n");
	int s = 0;
	for(int i=1;i<d;i++)
	{
		if(count[i].size()>=c)
		{
			s = i;
			break;
		}
	}
	
	for(int i=0;i<count[s].size()&&i<c;i++)
	{
		int v = count[s][i];
		while(1)
		{
			for(int j=0;j<V[v].size();j++)
			{
				if(height[V[v][j]]>height[v])
				{
					v = V[v][j];
					goto u;
				}
			}
			break;
			u:;
		}
		
		std::vector<int> temp;
		for(int j=0;j<=2;j++)
		{
			if(V[v][j]==prev[v]) continue;
			temp.push_back(V[v][j]);
		}
		
		if((height[v]-height[temp[0]]+1)%3!=0)
		{
			printf("%d\n",(height[v]-height[temp[0]]+1));
			printf("%d ",v);
			int w = temp[0];
			while(v!=w)
			{
				v = prev[v];
				printf("%d ",v);
			}
			printf("\n");
		}
		else if((height[v]-height[temp[1]]+1)%3!=0)
		{
			printf("%d\n",(height[v]-height[temp[1]]+1));
			printf("%d ",v);
			int w = temp[1];
			while(v!=w)
			{
				v = prev[v];
				printf("%d ",v);
			}
			printf("\n");
		}
		else
		{
			if(height[temp[0]]<height[temp[1]])
			{
				printf("%d\n",(height[temp[1]]-height[temp[0]]+2));
				printf("%d ",v);
				int w1 = temp[1];
				int w0 = temp[0];
				while(w0!=w1)
				{
					printf("%d ",w1);
					w1 = prev[w1];
				}
				printf("%d\n",w0);
			}
			else
			{
				printf("%d\n",(height[temp[0]]-height[temp[1]]+2));
				printf("%d ",v);
				int w1 = temp[1];
				int w0 = temp[0];
				while(w0!=w1)
				{
					printf("%d ",w0);
					w0 = prev[w0];
				}
				printf("%d\n",w1);
			}
		}
	}
}