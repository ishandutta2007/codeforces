#include <stdio.h>
#include <vector>
#include <stack>

std::vector<int> V[400010];
int check[400010];
std::stack<int> St;
void func(int k)
{
	if(check[k]) return;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) func(V[k][i]);
	St.push(k);
}

std::vector<int> V2[400010];
int color[400010];
void func2(int k, int C)
{
	if(color[k]) return;
	color[k] = C;
	for(int i=0;i<V2[k].size();i++) func2(V2[k][i],C);
}

int check3[400010];
int type[400010];
std::vector<int> V3[400010];
int func3(int k)
{
	//1 : one 2: many 3: inf 4: impo
	if(check3[k]) return check3[k];
	if(k==color[1])
	{
		if(type[k]==1) return check3[k] = 3;
		else return check3[k] = 1;
	}
	else
	{
		check3[k] = 4;
		for(int i=0;i<V3[k].size();i++)
		{
			int t = func3(V3[k][i]);
			if(t==4);
			else if(t==3) check3[k] = 3;
			else if(t==2)
			{
				if(check3[k]==4) check3[k] = 2;
				else if(check3[k]==1) check3[k] = 2;
			}
			else if(t==1)
			{
				if(check3[k]==4) check3[k] = 1;
				else if(check3[k]==1) check3[k] = 2;
			}
		}
		if(type[k]==1)
		{
			if(check3[k]<=2) check3[k] = 3;
		}
		return check3[k];
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) V2[i].clear();
		for(int i=1;i<=a;i++) V3[i].clear();
		for(int i=1;i<=a;i++) check[i] = check3[i] = color[i] = type[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V2[d].push_back(c);
		}
		
		for(int i=1;i<=a;i++) func(i);
		
		int C = 1;
		while(!St.empty())
		{
			int t = St.top();
			St.pop();
			if(color[t]==0) func2(t,C++);
		}
		C--;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				int t = V[i][j];
				if(color[i]==color[t]) type[color[i]] = 1;
				else V3[color[t]].push_back(color[i]);
			}
		}
		
		for(int i=1;i<=C;i++) func3(i);
		
		for(int i=1;i<=a;i++)
		{
			int t = check3[color[i]];
			if(t==1) printf("1 ");
			if(t==2) printf("2 ");
			if(t==3) printf("-1 ");
			if(t==4) printf("0 ");
		}
		printf("\n");
	}
}