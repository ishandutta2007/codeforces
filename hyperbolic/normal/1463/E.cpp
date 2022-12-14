#include <stdio.h>
#include <vector>

std::vector<int> V[300010];
std::vector<int> St;
int control = 0;
int check[300010];
void func(int k, int prev)
{
	//printf("%d %d %d!!\n",k,prev,check[k]);
	if(control) return;
	if(check[k]==1)
	{
		control = 1;
		return;
	}
	if(check[k]==2) return;
	check[k] = 1;
	
	for(int i=0;i<V[k].size();i++) func(V[k][i],k);
	
	check[k] = 2;
	St.push_back(k);
}

int x[300010],next[300010],prev[300010],color[300010],number[300010],start[300010];
int check2[300010];
int C = 1;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) next[i] = i;
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(next[c]!=c)
		{
			printf("0");
			return 0;
		}
		if(prev[d]!=0)
		{
			printf("0");
			return 0;
		}
		next[c] = d;
		prev[d] = c;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(prev[i]==0)
		{
			int p = i;
			check2[i] = 1;
			while(p!=next[p])
			{
				p = next[p];
				if(check2[p])
				{
					printf("0");
					return 0;
				}
				check2[p] = 1;
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		if(check2[i]==0)
		{
			printf("0");
			return 0;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(color[i]==0&&prev[i]==0)
		{
			int p = i;
			color[p] = C;
			int n = 1;
			number[p] = n;
			start[C] = i;
			
			while(p!=next[p])
			{
				p = next[p];
				n++;
				color[p] = C;
				number[p] = n;
			}
			C++;
		}
	}
	
	int root = -1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=0)
		{
			if(color[x[i]]==color[i])
			{
				if(number[x[i]]>number[i])
				{
					printf("0");
					return 0;
				}
			}
			else V[color[x[i]]].push_back(color[i]);
		}
		else root = color[i];
	}
	func(root,0);
	if(control) printf("0");
	else
	{
		for(int i=St.size()-1;i>=0;i--)
		{
			int p = start[St[i]];
			printf("%d ",p);
			while(p!=next[p]) p = next[p], printf("%d ",p);
		}
	}
}