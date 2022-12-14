#include <stdio.h>
#include <map>

std::map<int,int> M;
int x[200010];
int y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int sum = 0;
	long long int ans = 0;
	M[0]++;
	for(int i=1;i<=a;i++)
	{
		sum ^= x[i];
		int c1 = M[sum];
		int c2 = M[((1<<b)-1)-sum];
		if(c1<c2)
		{
			ans += c1;
			M[sum]++;
		}
		else
		{
			ans += c2;
			M[((1<<b)-1)-sum]++;
		}
	}
	printf("%lld",(long long int)a*(a+1)/2-ans);
}