#include <stdio.h>
#include <vector>
std::vector<int> V[200010];
int check[200010];
void func(int s, int t)
{
	int color = 1;
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i]==t) continue;
		while(color==check[s]||color==check[t]) color++;
		check[V[s][i]] = color++;
		func(V[s][i],s);
	}
}
int main()
{
	int a,b,c;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	int max = V[1].size();
	for(int i=2;i<=a;i++) max = max>V[i].size()?max:V[i].size();
	printf("%d\n",max+1);
	check[1] = 1;
	func(1,0);
	for(int i=1;i<=a;i++) printf("%d ",check[i]);
}