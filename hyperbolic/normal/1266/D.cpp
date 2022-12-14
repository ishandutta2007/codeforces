#include <stdio.h>
#include <vector>
struct str{
	int x0;
	int y0;
	long long int value;
};
std::vector<int> V1,V2;
std::vector<str> V;

long long int sum[100010];
void func(int s, int t)
{
	if(s>=V1.size()) return;
	if(sum[V1[s]]+sum[V2[t]]==0)
	{
		V.push_back({V1[s],V2[t],sum[V1[s]]});
		func(s+1,t+1);
	}
	else
	{
		if(sum[V1[s]]+sum[V2[t]]>0)
		{
			V.push_back({V1[s],V2[t],-sum[V2[t]]});
			sum[V1[s]] += sum[V2[t]];
			func(s,t+1);
		}
		else
		{
			V.push_back({V1[s],V2[t],sum[V1[s]]});
			sum[V2[t]] += sum[V1[s]];
			func(s+1,t);
		}
	}
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		sum[c]+=e, sum[d]-=e;
	}
	for(int i=1;i<=a;i++)
	{
		if(sum[i]>0) V1.push_back(i);
		if(sum[i]<0) V2.push_back(i);
	}
	func(0,0);
	printf("%d\n",V.size());
	for(int i=0;i<V.size();i++)
	{
		printf("%d %d %lld\n",V[i].x0,V[i].y0,V[i].value);
	}
}