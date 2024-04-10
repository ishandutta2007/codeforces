#include <stdio.h>
#include <vector>
#include <algorithm>

int x[100010];
std::vector<long long int> V1,V2;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]>c) V1.push_back(x[i]);
		else V2.push_back(x[i]);
	}
	std::sort(V1.begin(),V1.end());
	for(int i=1;i<V1.size();i++) V1[i]+=V1[i-1];
	std::sort(V2.begin(),V2.end());
	for(int i=1;i<V2.size();i++) V2[i]+=V2[i-1];
	
	long long int ans = 0;
	for(int i=V1.size();i<=a;i++)
	{
		int s;
		if(i==0) s = 0;
		else s = (i-1)/(b+1)+1;
		
		int t = i-V1.size();
		if(s>V1.size()) continue;
		if(t>V2.size()) continue;
		
		long long int S = 0;
		if(s==0);
		else if(s==V1.size()) S += V1[V1.size()-1];
		else S += (V1[V1.size()-1] - V1[V1.size()-1-s]);
		
		if(t==V2.size());
		else if(t==0) S += V2[V2.size()-1];
		else S += (V2[V2.size()-1] - V2[V2.size()-1-(V2.size()-t)]);
		ans = ans>S?ans:S;
	}
	printf("%lld",ans);
}