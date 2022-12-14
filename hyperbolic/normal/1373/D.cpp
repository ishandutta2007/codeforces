#include <stdio.h>
#include <vector>

int x[200010];
std::vector<int> y,z;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		y.clear();
		z.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i+1<=a;i+=2) y.push_back(-x[i]+x[i+1]);
		for(int i=2;i+1<=a;i+=2) z.push_back(x[i]-x[i+1]);
		
		long long int M = 0;
		long long int S = 0;
		for(int i=0;i<y.size();i++)
		{
			S += y[i];
			S = S>0?S:0;
			M = M>S?M:S;
		}
		S = 0;
		for(int i=0;i<z.size();i++)
		{
			S += z[i];
			S = S>0?S:0;
			M = M>S?M:S;
		}
		
		long long int count = 0;
		for(int i=1;i<=a;i+=2) count += x[i];
		printf("%lld\n",count+M);
	}
}