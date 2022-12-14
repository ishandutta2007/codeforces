#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
int check[1000010];
int x[1000010];
int ans[1000010];
std::vector<int> V[1000010];
std::priority_queue<int> Q;
std::priority_queue<int, std::vector<int> , std::greater<int> > Q2;
std::stack<int> St;
void func(int k)
{
	check[k] = 1;
	St.push(k);
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i]]==0) func(V[k][i]);
	}
}

int main()
{
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0) func(i);
		while(!St.empty())
		{
			Q.push(x[St.top()]);
			Q2.push(St.top());
			St.pop();
		}
		while(!Q.empty())
		{
			ans[Q2.top()] = Q.top();
			Q2.pop();
			Q.pop();
		}
	}
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}