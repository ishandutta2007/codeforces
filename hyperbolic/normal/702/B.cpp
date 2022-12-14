#include <stdio.h>
#include <algorithm>
#include <map>

std::map<int,long long int> M;
int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) M[x[i]]++;
	std::sort(x+1,x+a+1);
	
	long long int count = 0;
	int C = 30;
	for(int k=2;C--;k*=2)
	{
		for(int i=1;i<=a;i++)
		{
			if(2*x[i]==k) continue;
			if(x[i]>k-x[i]) continue;
			count += M[k-x[i]];
		}
		for(std::map<int,long long int> ::iterator it = M.begin();it!=M.end();it++) if(2*(it->first)==k) count += (it->second)*((it->second)-1)/2;
	}
	
	printf("%lld",count);
}