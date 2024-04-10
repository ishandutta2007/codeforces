#include <stdio.h>
#include <queue>
#include <vector>
#include <stack>

char x[400010];
int y[400010];
std::vector<char> V[400010];
std::vector<int> check[400010];
int max[400010],count[400010],next[400010];

int a,b;

std::stack<int> St;
std::vector<int> V2[400010],V3[400010];
int check2[400010];

void func2(int k)
{
	if(check2[k]) return;
	check2[k] = 1;
	for(int i=0;i<V2[k].size();i++) func2(V2[k][i]);
	St.push(k);
}

int color[400010];
void func3(int k, int C)
{
	if(color[k]) return;
	color[k] = C;
	for(int i=0;i<V3[k].size();i++) func3(V3[k][i],C);
}

std::vector<int> temp;
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) check[i].push_back(0);
	
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		V[i].push_back(0);
		for(int j=1;j<=b;j++) V[i].push_back(x[j]);
	}
	
	for(int i=1;i<=a;i++) if(V[i][1]=='#') temp.push_back(i);
	for(int j=2;j<=b;j++)
	{
		for(int i=1;i<=a;i++)
		{
			if(V[i][j]=='#'&&temp.size()>0)
			{
				if(temp.back()<i) continue;
				int min = 0, max = temp.size()-1;
				int p = max;
				while(min<=max)
				{
					int h = (min+max)/2;
					if(temp[h]>=i)
					{
						p = h;
						max = h-1;
					}
					else min = h+1;
				}
				V2[(i-1)*b+j].push_back((temp[p]-1)*b+(j-1));
			}
		}
		temp.clear();
		for(int i=1;i<=a;i++) if(V[i][j]=='#') temp.push_back(i);
	}
	
	temp.clear();
	for(int i=1;i<=a;i++) if(V[i][b]=='#') temp.push_back(i);
	for(int j=b-1;j>=1;j--)
	{
		for(int i=1;i<=a;i++)
		{
			if(V[i][j]=='#'&&temp.size()>0)
			{
				if(temp.back()<i) continue;
				int min = 0, max = temp.size()-1;
				int p = max;
				while(min<=max)
				{
					int h = (min+max)/2;
					if(temp[h]>=i)
					{
						p = h;
						max = h-1;
					}
					else min = h+1;
				}
				V2[(i-1)*b+j].push_back((temp[p]-1)*b+(j+1));
			}
		}
		temp.clear();
		for(int i=1;i<=a;i++) if(V[i][j]=='#') temp.push_back(i);
	}
	
	for(int j=1;j<=b;j++)
	{
		int t = -1;
		for(int i=1;i<=a;i++)
		{
			if(V[i][j]=='#')
			{
				if(t!=-1) V2[(t-1)*b+j].push_back((i-1)*b+j);
				t = i;
			}
		}
	}
	for(int j=1;j<=b;j++)
	{
		for(int i=2;i<=a;i++)
		{
			if(V[i][j]=='#'&&V[i-1][j]=='#') V2[(i-1)*b+j].push_back((i-2)*b+j);
		}
	}
	
	for(int i=1;i<=a*b;i++) for(int j=0;j<V2[i].size();j++) V3[V2[i][j]].push_back(i);
	
	for(int i=1;i<=a*b;i++) if(check2[i]==0) func2(i);
	
	int C = 1;
	while(!St.empty())
	{
		int v = St.top();
		St.pop();
		
		int s = (v-1)/b + 1;
		int t = (v-1)%b + 1;
		if(V[s][t]=='.') continue;
		if(color[v]) continue;
		func3(v,C);
		C++;
	}
	
	for(int i=1;i<=a*b;i++) count[color[i]] = 1;
	for(int i=1;i<=a*b;i++)
	{
		for(int j=0;j<V2[i].size();j++)
		{
			int t = V2[i][j];
			if(color[i]!=color[t]) count[color[t]] = 0;
		}
	}
	
	
	
	int ans = 0;
	for(int i=1;i<=a*b;i++) ans += count[i];
	printf("%d",ans);
}