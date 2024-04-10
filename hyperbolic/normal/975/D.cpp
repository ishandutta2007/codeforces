#include <stdio.h>
#include <map>

std::map<long long int,int> M;
std::map< std::pair<int,int> , int> count;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		long long int k = (long long int)b*e-f;
		ans += 2*M[k];
		M[k]++;
		ans -= 2*count[std::make_pair(e,f)];
		count[std::make_pair(e,f)]++;
	}
	printf("%lld",ans);
}