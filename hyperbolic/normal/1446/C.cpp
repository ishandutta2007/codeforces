#include <stdio.h>
#include <vector>

int func(int k, std::vector<int>& V)
{
	if(k<0) return 0;
	if(V.size()<=1) return 0;
	
	int count = 0;
	for(int i=0;i<V.size();i++) if((V[i]&(1<<k))!=0) count++;
	if(count<=1)
	{
		std::vector<int> V2;
		for(int i=0;i<V.size();i++) if((V[i]&(1<<k))==0) V2.push_back(V[i]);
		return func(k-1,V2);
	}
	else
	{
		if(count==V.size()) return func(k-1,V);
		
		std::vector<int> V2,V3;
		for(int i=0;i<V.size();i++) if((V[i]&(1<<k))==0) V2.push_back(V[i]);
		for(int i=0;i<V.size();i++) if((V[i]&(1<<k))!=0) V3.push_back(V[i]);
		int s2 = func(k-1,V3)+(V2.size()-1);
		int s1 = func(k-1,V2)+(count-1);
		return s1<s2?s1:s2;
	}
}
std::vector<int> V;
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) V.push_back(x[i]);
	printf("%d",func(30,V));
}