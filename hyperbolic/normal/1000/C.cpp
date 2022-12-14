#include <stdio.h>
#include <map>

std::map<long long int,int> M;
long long int ans[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		M[b]++;
		M[c+1]--;
	}
	
	int control = 0;
	long long int prev = 0;
	int count = 0;
	for(std::map<long long int,int> ::iterator it = M.begin();it!=M.end();it++)
	{
		if(control==1) ans[count] += (it->first)-prev;
		control = 1;
		count += (it->second);
		prev = (it->first);
	}
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
}