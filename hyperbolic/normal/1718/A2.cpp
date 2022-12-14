#include <stdio.h>
#include <map>

std::map<int,int> M;
int x[100010],y[100010];
long long int DP[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a+1;i++) x[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		DP[a+1] = 0;
		DP[a+2] = 0;
		DP[a+3] = 0;
		for(int i=1;i<=a;i++) y[i] = x[i];
		for(int i=1;i<=a;i++) y[i] ^= y[i-1];
		
		for(int i=a;i>=1;i--)
		{
			long long int s1 = DP[i+1], s2 = 123456789;
			if(x[i]>0) s1++;
			
			int t = M[y[i-1]];
			if(t!=0) s2 = DP[t+1] + (t-i);
			DP[i] = s1<s2?s1:s2;
			M[y[i]] = i;
		}
		printf("%lld\n",DP[1]);
	}
}