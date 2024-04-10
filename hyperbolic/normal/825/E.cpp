#include <stdio.h>
#include <queue>

std::priority_queue<int> Q;
int check[100010];
std::vector<int> V[100010],V2[100010];
int score[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V2[d].push_back(c);
	}
	for(int i=1;i<=a;i++) score[i] = V[i].size();
	for(int i=1;i<=a;i++) if(score[i]==0) Q.push(i);
	int C = a;
	while(!Q.empty())
	{
		int k = Q.top();
		Q.pop();
		check[k] = C--;
		for(int i=0;i<V2[k].size();i++)
		{
			score[V2[k][i]]--;
			if(score[V2[k][i]]==0) Q.push(V2[k][i]);
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",check[i]);
}