#include <stdio.h>
#include <stack>
#include <vector>
#define MAX 123456789

std::vector<int> V[200010],V2[200010];


int check[200010];
std::stack<int> St;
void init(int k)
{
	if(check[k]==1) return;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) init(V[k][i]);
	St.push(k);
}

int color[200010];
void makeSCC(int k, int c)
{
	if(color[k]>0) return;
	color[k] = c;
	for(int i=0;i<V2[k].size();i++) makeSCC(V2[k][i],c);
}

int x[200010],cost[200010];
std::vector<int> V3[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		V[i].push_back(b);
		V2[b].push_back(i);
	}
	for(int i=1;i<=a;i++) init(i);
	
	int c = 1;
	while(!St.empty())
	{
		int k = St.top();
		St.pop();
		if(color[k]==0) makeSCC(k,c++);
	}
	for(int i=1;i<=a;i++) cost[i] = MAX;
	for(int i=1;i<=a;i++) cost[color[i]] = cost[color[i]]<x[i]? cost[color[i]]:x[i];
	for(int i=1;i<=a;i++) if(color[i]!=color[V[i][0]]) V3[color[i]].push_back(color[V[i][0]]);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) if(V3[i].size()==0&&cost[i]<MAX) ans += cost[i];
	printf("%lld",ans);
}