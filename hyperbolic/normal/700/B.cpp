#include <stdio.h>
#include <vector>
std::vector<int> V[200010];
int check[200010],size[200010];
int check2[200010],x[200010];
int func(int k)
{
	int s=0;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i]]==0) s+=func(V[k][i]);
	}
	if(x[k]==1) s++;
	return size[k] = s;
}
long long int func2(int k ,int count)
{
	long long int s = 0;
	check2[k] = 1;
	if(x[k]==1) s+=count;
	for(int i=0;i<V[k].size();i++)
	{
		if(check2[V[k][i]]==0) s+=func2(V[k][i],count+1);
	}
	return s;
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=2*b;i++)
	{
		scanf("%d",&c);
		x[c] = 1;
	}
	for(int i=1;i<a;i++)
	{
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	func(1);
	for(int i=1;i<=a;i++) check[i] = 0;
	int s = 1;
	
	u:;
	check[s] = 1;
	for(int i=0;i<V[s].size();i++)
	{
		if(check[V[s][i]]==0)
		{
			if(size[V[s][i]]>b)
			{
				s = V[s][i];
				goto u;
			}
		}
	}
	
	printf("%I64d",func2(s,0));
}