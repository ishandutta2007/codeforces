#include <stdio.h>
#include <vector>

std::vector<int> V[100010],ans[5];
int check[100010];
int control = 0;
void func(int k, int col)
{
	if(check[k]>0)
	{
		if(check[k]!=col) control = 1;
		return;
	}
	check[k] = col;
	
	for(int i=0;i<V[k].size();i++) func(V[k][i],3-col);
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	for(int i=1;i<=a;i++) if(check[i]==0) func(i,1);
	if(control)
	{
		printf("-1");
		return 0;
	}
	
	for(int i=1;i<=a;i++) ans[check[i]].push_back(i);
	
	for(int i=1;i<=2;i++)
	{
		printf("%d\n",ans[i].size());
		for(int j=0;j<ans[i].size();j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
}