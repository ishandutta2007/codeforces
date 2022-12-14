#include <stdio.h>
#include <vector>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

char x[500010];
std::pair<int,int> type[500010];
int ans[500010];
int last[510][510];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int s1 = 0 ,s2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='D') s1++;
			else s2++;
			
			int g = gcd(s1,s2);
			int t1 = s1/g, t2 = s2/g;
			type[i] = std::make_pair(t1,t2);
			
			if(t1+t2<=500)
			{
				int L = last[t1][t2];
				ans[i] = ans[L]+1;
				last[t1][t2] = i;
			}
			else
			{
				for(int j=i-(t1+t2);j>=0;j-=(t1+t2))
				{
					if(j==0)
					{
						ans[i] = 1;
						break;
					}
					else if(type[j].first==t1 && type[j].second==t2)
					{
						ans[i] = ans[j]+1;
						break;
					}
				}
			}
		}
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
		
		for(int i=1;i<=a;i++)
		{
			if(type[i].first+type[i].second<=500) last[type[i].first][type[i].second] = 0;
			type[i] = std::make_pair(0,0);
		}
	}
}