#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V[100010];
std::vector<int> V2;

int check[100010];
int main()
{
	int a;
	scanf("%d",&a);
	if(a==2)
	{
		printf("0");
		return 0;
	}
	
	for(int i=0;i<a-1;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back({c,i});
		V[c].push_back({b,i});
	}
	
	
	for(int i=1;i<=a;i++) if(V[i].size()==1) V2.push_back(V[i][0].second);
	
	if(V2.size()==2)
	{
		for(int i=1;i<a;i++) printf("%d\n",i-1);
		return 0;
	}
	else
	{
		for(int i=0;i<a-1;i++) check[i] = -1;
		for(int i=0;i<=2;i++) check[V2[i]] = i;
		int p = 3;
		for(int i=0;i<a-1;i++) if(check[i]==-1) check[i] = p++;
		for(int i=0;i<a-1;i++) printf("%d\n",check[i]);
	}
}