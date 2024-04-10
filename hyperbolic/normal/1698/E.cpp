#include <stdio.h>
#include <set>
#define MOD 998244353

int x[200010],y[200010],pos[200010];
std::set<int> S;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) y[i] = -1;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			x[c] = i;
		}
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			if(c!=-1) y[c] = i;
		}
		
		for(int i=1;i<=a;i++) pos[x[i]] = i;
		for(int i=1;i<=a;i++) if(y[i]!=-1) S.insert(y[i]);
		
		long long int ans = 1;
		int C = 0;
		for(int i=1;i<=b;i++) if(S.find(x[i])==S.end()) C++;
		for(int i=1;i<=a;i++)
		{
			if(i+b<=a) if(S.find(x[i+b])==S.end()) C++;
			
			if(y[i]==-1)
			{
				ans*=C, ans%=MOD;
				C--;
			}
			else if(pos[y[i]]>i+b) ans*=0;
		}
		printf("%lld\n",ans);
	}
}