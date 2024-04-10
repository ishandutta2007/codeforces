#include <stdio.h>
#include <vector>

std::vector<int> M;
int ans = 0;

void func(std::vector< std::pair<long long int,int> > &V, int C)
{
	if(V.size()==0) return;
	if(C>60) return;
	
	std::vector< std::pair<long long int,int> > V1,V2;
	for(int i=0;i<V.size();i++)
	{
		if(V[i].first%2==1) V1.push_back(V[i]);
		else V2.push_back(V[i]);
	}
	if(V1.size()>ans)
	{
		ans = V1.size();
		M.clear();
		for(int i=0;i<V1.size();i++) M.push_back(V1[i].second);
	}
	for(int i=0;i<V2.size();i++) V2[i].first /= 2;
	func(V2,C+1);
}

std::vector< std::pair<long long int,int> > V;
int check[200010];
long long int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) V.push_back({x[i],i});
	func(V,0);
	
	printf("%d\n",a-ans);
	for(int i=0;i<M.size();i++) check[M[i]] = 1;
	for(int i=1;i<=a;i++) if(check[i]==0) printf("%lld ",x[i]);
}