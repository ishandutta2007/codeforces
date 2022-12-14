#include <stdio.h>
#include <set>

int x[3010];
std::set<int> S;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) x[i] += x[i-1];
		for(int i=1;i<=a;i++) S.insert(x[i]);
		for(int i=a;i>=1;i--)
		{
			if(x[a]%i==0)
			{
				int t = x[a]/i;
				for(int j=t;j<=x[a];j+=t)
				{
					if(S.find(j)==S.end())
					{
						goto u;
					}
				}
				printf("%d\n",a-i);
				goto v;
				u:;
			}
		}
		v:;
	}
}