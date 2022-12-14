#include <stdio.h>
#include <vector>

char x[2010],y[2010];
std::vector< std::pair<int,int> > ans;

void func(int s, int t)
{
	ans.push_back(std::make_pair(s,t));
	for(int i=s;i<=t;i++) y[i] = x[i];
	for(int i=s;i<=t;i++) x[i] = y[s+t-i];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		
		for(int i=1;i<b;i++)
		{
			int p = 0;
			for(int j=2*i-1;j<=a;j++)
			{
				if(x[j]=='(')
				{
					p = j;
					break;
				}
			}
			func(2*i-1,p);
			
			p = 0;
			for(int j=2*i;j<=a;j++)
			{
				if(x[j]==')')
				{
					p = j;
					break;
				}
			}
			func(2*i,p);
		}
		for(int i=2*b-1;i<2*b-1 + (a/2 - b + 1);i++)
		{
			int p = 0;
			for(int j=i;j<=a;j++)
			{
				if(x[j]=='(')
				{
					p = j;
					break;
				}
			}
			func(i,p);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}
}