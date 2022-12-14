#include <stdio.h>
#include <vector>
char x[10];
std::vector< std::pair<int,int> > V[110];
int check[110][110][30];
int func(int s, int t, int k) //1 win 2 lose
{
	if(check[s][t][k]) return check[s][t][k];
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i].second>=k)
		{
			if(func(t,V[s][i].first,V[s][i].second)==2) return check[s][t][k] = 1;
		}
	}
	return check[s][t][k] = 2;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		char e;
		scanf("%d %d %c",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e-'a'+1));
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(func(i,j,0)==1) printf("A");
			else printf("B");
		}
		printf("\n");
	}
}