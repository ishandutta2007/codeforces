#include <stdio.h>
#include <set>

long long int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int s = 1, t = 0;
		for(int i=1;i<=a;i++)
		{
			long long int b;
			scanf("%lld",&b);
			if(b==0) t++;
			else x[s++] = b;
		}
		t = t<3?t:3;
		for(int i=1;i<=t;i++) x[s++] = 0;
		s--;
		a = s;
		
		if(a>=10) printf("NO\n");
		else
		{
			std::set<long long int> S;
			for(int i=1;i<=a;i++) S.insert(x[i]);
			
			for(int i=1;i<=a;i++)
			{
				for(int j=i+1;j<=a;j++)
				{
					for(int k=j+1;k<=a;k++)
					{
						if(S.find(x[i]+x[j]+x[k])==S.end())
						{
							printf("NO\n");
							goto u;
						}
					}
				}
			}
			printf("YES\n");
			u:;
		}
	}
}