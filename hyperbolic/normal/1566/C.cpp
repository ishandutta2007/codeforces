#include <stdio.h>
#include <vector>

std::vector<int> V;
char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]+y[i]==1+'0'+'0')
			{
				ans += 2;
				if(V.size()>0)
				{
					int C = 0;
					for(int j=0;j<V.size();j++)
					{
						if(V[j]==0)
						{
							if(C==0) ans++, C = 1;
							else if(C==1) ans++, C = 1;
							else if(C==2) ans+=2, C = 0;
						}
						else
						{
							if(C==0) C = 2;
							else if(C==1) ans++, C = 0;
							else if(C==2) C = 2;
						}
					}
				}
				V.clear();
			}
			else
			{
				if(x[i]=='0') V.push_back(0);
				else V.push_back(1);
			}
		}
		
		if(V.size()>0)
		{
			int C = 0;
			for(int j=0;j<V.size();j++)
			{
				if(V[j]==0)
				{
					if(C==0) ans++, C = 1;
					else if(C==1) ans++, C = 1;
					else if(C==2) ans+=2, C = 0;
				}
				else
				{
					if(C==0) C = 2;
					else if(C==1) ans++, C = 0;
					else if(C==2) C = 2;
				}
			}
		}
		V.clear();
		
		printf("%d\n",ans);
	}
}