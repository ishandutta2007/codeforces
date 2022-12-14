#include <stdio.h>
#include <stack>
std::stack< std::pair<int,int> > St;
int x[110][110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	if(a<b)
	{
		for(int i=1;i<=a;i++)
		{
			int c = x[i][1];
			for(int j=2;j<=b;j++) c = c<x[i][j]?c:x[i][j];
			for(int j=1;j<=b;j++) x[i][j]-=c;
			while(c--) St.push(std::make_pair(1,i));
		}
		for(int j=1;j<=b;j++)
		{
			int c = x[1][j];
			for(int i=2;i<=a;i++) c = c<x[i][j]?c:x[i][j];
			for(int i=1;i<=a;i++) x[i][j]-=c;
			while(c--) St.push(std::make_pair(2,j));
		}
	}
	else
	{
		for(int j=1;j<=b;j++)
		{
			int c = x[1][j];
			for(int i=2;i<=a;i++) c = c<x[i][j]?c:x[i][j];
			for(int i=1;i<=a;i++) x[i][j]-=c;
			while(c--) St.push(std::make_pair(2,j));
		}
		for(int i=1;i<=a;i++)
		{
			int c = x[i][1];
			for(int j=2;j<=b;j++) c = c<x[i][j]?c:x[i][j];
			for(int j=1;j<=b;j++) x[i][j]-=c;
			while(c--) St.push(std::make_pair(1,i));
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]!=0)
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d\n",St.size());
	while(!St.empty())
	{
		std::pair<int,int> p = St.top();
		St.pop();
		if(p.first==1) printf("row %d\n",p.second);
		else printf("col %d\n",p.second);
	}
}