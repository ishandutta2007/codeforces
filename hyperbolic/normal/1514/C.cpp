#include <stdio.h>
#include <vector>

std::vector<int> V;
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) if(gcd(a,i)==1) V.push_back(i);
	
	long long int ans = 1;
	for(int i=0;i<V.size();i++) ans *= V[i], ans %= a;
	
	if(ans==1)
	{
		printf("%d\n",V.size());
		for(int i=0;i<V.size();i++) printf("%d ",V[i]);
	}
	else
	{
		printf("%d\n",V.size()-1);
		for(int i=0;i<V.size();i++) if(V[i]!=ans) printf("%d ",V[i]);
	}
}