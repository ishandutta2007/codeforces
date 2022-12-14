#include <stdio.h>
#define MOD 1000000007
int x[200010],y[200010],next[200010];
int check[200010],check2[200010],count[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		for(int i=1;i<=a;i++) next[i] = check[i] = check2[i] = count[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) next[y[i]] = i;
		
		int C = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				C++;
				int cnt = 0;
				int p = i;
				while(check[p]==0)
				{
					cnt++;
					check[p] = C;
					p = next[x[p]];
				}
				count[C] = cnt;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b!=0) check2[check[i]] = 1;
		}
		
		int ans = 1;
		for(int i=1;i<=C;i++) if(check2[i]==0&&count[i]>1) ans*=2, ans%=MOD;
		printf("%d\n",ans);
	}
}