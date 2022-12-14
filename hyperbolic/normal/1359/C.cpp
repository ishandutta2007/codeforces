#include <stdio.h>
#include <vector>
#include <algorithm>
double abs(double k)
{
	return k>0?k:-k;
}
std::vector<long long int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		double s1 = (double)(a+b)/2;
		if(a+b>=2*c)
		{
			printf("2\n");
			continue;
		}
		
		long long int k = (a-c)/(2*c-a-b);
		double s2 = (double)((k+1)*a+k*b)/(2*k+1);
		double s3 = (double)((k+2)*a+(k+1)*b)/(2*k+3);
		s1 = abs(s1-c), s2 = abs(s2-c), s3 = abs(s3-c);
		double min = s1<s2?s1<s3?s1:s3:s2<s3?s2:s3;
		if(min==s1) V.push_back(2);
		if(min==s2) V.push_back(2*k+1);
		if(min==s3) V.push_back(2*k+3);
		std::sort(V.begin(),V.end());
		printf("%lld\n",V[0]);
		
	}
}