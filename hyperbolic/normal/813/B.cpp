#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<long long int> V1,V2,V3;
int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long int p;
	
	p = 1;
	V1.push_back(1);
	while(1)
	{
		if(p>=(d/a)+1) break;
		else
		{
			if(a*p>d) break;
			p*=a;
			V1.push_back(p);
		}
	}
	
	p = 1;
	V2.push_back(1);
	while(1)
	{
		if(p>=(d/b)+1) break;
		else
		{
			if(b*p>d) break;
			p*=b;
			V2.push_back(p);
		}
	}
	
	for(int i=0;i<V1.size();i++)
	{
		for(int j=0;j<V2.size();j++)
		{
			long long int t= V1[i]+V2[j];
			if(c<=t&&t<=d) V3.push_back(t);
		}
	}
	V3.push_back(c-1);
	V3.push_back(d+1);
	std::sort(V3.begin(),V3.end());
	
	long long int ans = 0;
	for(int i=0;i+1<V3.size();i++) ans = ans>V3[i+1]-V3[i]-1?ans:V3[i+1]-V3[i]-1;
	printf("%lld",ans);
}