#include <stdio.h>
#include <map>

std::map<long long int, long long int> M;
long long int a,b,c;
long long int func(int k)
{
	if(k==1) return b;
	if(M[k]) return M[k];
	
	if(k%2==0)
	{
		long long int s1 = k*b;
		long long int s2 = func(k/2)+c;
		return M[k] = s1<s2?s1:s2;
	}
	else
	{
		long long int s1 = func(k-1)+b;
		long long int s2 = func(k+1)+b;
		return M[k] = s1<s2?s1:s2;
	}
}

int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld",func(a));
}