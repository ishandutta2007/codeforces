#include <stdio.h>
#include <map>
#define MOD 998244353

int check[200010];
std::map<int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			M[c] = i;
		}
		for(int i=0;i<=a+1;i++) check[i] = 0;
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			check[M[c]] = i;
		}
		
		long long int ans = 1;
		for(int i=1;i<=a;i++)
		{
			if(check[i]>0)
			{
				int s = i-1;
				int t = i+1;
				int count = 0;
				if(s>=1 && check[s]<check[i]) count++;
				if(t<=a && check[t]<check[i]) count++;
				ans *= count;
				ans%=MOD;
			}
		}
		printf("%lld\n",ans);
	}
}