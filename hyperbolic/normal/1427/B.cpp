#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V;
char x[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		x[a+1] = 'W';
		
		for(int i=1;i<=a;i++) if(x[i]=='W') goto u;
		if(b==0) printf("0\n");
		else printf("%d\n",2*b-1);
		continue;
		u:;
		
		int p = 0;
		int left = 0, right = 0;
		for(int i=1;i<=a+1;i++)
		{
			if(x[i]=='W')
			{
				if(p>0)
				{
					if(i==a+1) right = i-1-p;
					else if(i-1-p>=1) V.push_back(i-1-p);
				}
				else left = i-1;
				p = i;
			}
		}
		std::sort(V.begin(),V.end());
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='W')
			{
				if(x[i-1]=='W') ans +=2;
				else ans++;
			}
		}
		for(int i=0;i<V.size();i++)
		{
			if(b>=V[i])
			{
				ans += (2*V[i]+1);
				b -= V[i];
			}
			else
			{
				ans += 2*b;
				b = 0;
			}
		}
		if(b>0&&right+left>0)
		{
			if(right+left>b) ans +=(2*b);
			else ans += (2*left+2*right);
		}
		printf("%d\n",ans);
	}
}