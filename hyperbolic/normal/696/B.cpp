#include <stdio.h>
#include <vector>
std::vector<int> V[100010];
int up[100010];
int check[100010];
double flow[100010];
int size(int k)
{
	if(check[k]) return check[k];
	int count = 0;
	for(int i=0;i<V[k].size();i++) count+=size(V[k][i]);
	return check[k]=count+1;
}
void func(int k)
{
	flow[k]+=1.0;
	for(int i=0;i<V[k].size();i++) flow[V[k][i]]+=(double)(size(k)-size(V[k][i])-1)/2;
	for(int i=0;i<V[k].size();i++) func(V[k][i]);
}
void func2(int k)
{
	for(int i=0;i<V[k].size();i++) flow[V[k][i]]+=flow[k];
	for(int i=0;i<V[k].size();i++) func2(V[k][i]);
}
int main()
{
	int a,b;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
	{
		scanf("%d",&b);
		up[i] = b;
		V[b].push_back(i);
	}
	func(1);
	func2(1);
	for(int i=1;i<=a;i++) printf("%lf ",flow[i]);
}