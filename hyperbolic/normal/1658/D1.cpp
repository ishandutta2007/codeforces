#include <stdio.h>
#include <vector>
#include <algorithm>

int x[1000010],y[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int c = b-a+1;
		for(int i=1;i<=c;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+c+1);
		int C = 0;
		int C2 = 0;
		for(int j=18;j>=0;j--)
		{
			int p = c+1;
			for(int i=c;i>=1;i--) if(x[i]>=(1<<j)) p = i;
			if(p==1)
			{
				if(((a>>j)&1)==1)
				{
					//a -= (1<<j);
					//b -= (1<<j);
				}
				else
				{
					C += (1<<j);
				}
				C2 += (1<<j);
				for(int i=1;i<=c;i++) x[i] -= (1<<j);
			}
			else if(p==c+1)
			{
				if(((a>>j)&1)==1)
				{
					C += (1<<j);
					//a -= (1<<j);
					//b -= (1<<j);
				}
			}
			else
			{
				//1~p-1, p~a
				//case 1
				int ans;
				ans = C;
				for(int k=j-1;k>=0;k--)
				{
					int count0 = 0, count1 = 0;
					for(int i=p;i<=c;i++)
					{
						if(((x[i]>>k)&1)==0) count0++;
						else count1++;
					}
					if(count1>count0) ans += (1<<k);
					else if(count1<count0);
					else
					{
						int count2 = 0, count3 = 0;
						for(int i=1;i<p;i++)
						{
							if(((x[i]>>k)&1)==0) count2++;
							else count3++;
						}
						if(count2>count3) ans += (1<<k);
					}
				}
				for(int i=1;i<=c;i++) y[i] = ((x[i]+C2)^ans);
				std::sort(y+1,y+c+1);
				
				if(y[1]==a && y[c]==b)
				{
					printf("%d\n",ans);
					goto u;
				}
				
				//case 2
				ans = C+(1<<j);
				for(int k=j-1;k>=0;k--)
				{
					int count0 = 0, count1 = 0;
					for(int i=1;i<=p-1;i++)
					{
						if(((x[i]>>k)&1)==0) count0++;
						else count1++;
					}
					if(count1>count0) ans += (1<<k);
					else if(count1<count0);
					else
					{
						int count2 = 0, count3 = 0;
						for(int i=p;i<=c;i++)
						{
							if(((x[i]>>k)&1)==0) count2++;
							else count3++;
						}
						if(count2>count3) ans += (1<<k);
					}
				}
				for(int i=1;i<=c;i++) y[i] = ((x[i]+C2)^ans);
				std::sort(y+1,y+c+1);
				if(y[1]==a && y[c]==b)
				{
					printf("%d\n",ans);
					goto u;
				}
			}
		}
		printf("%d\n",C);
		u:;
	}
}