#include <stdio.h>
#include <deque>
int x[200010],y[200010],z[200010];
int check[200010];
std::deque<int> D;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		y[1] = x[1];
		for(int i=1;i<x[1];i++) D.push_back(i);
		for(int i=2;i<=a;i++)
		{
			if(x[i]!=x[i-1])
			{
				y[i] = x[i];
				for(int j=x[i-1]+1;j<x[i];j++) D.push_back(j);
			}
			else
			{
				y[i] = D.front();
				D.pop_front();
			}
		}
		z[1] = x[1];
		for(int i=1;i<x[1];i++) D.push_back(i);
		for(int i=2;i<=a;i++)
		{
			if(x[i]!=x[i-1])
			{
				z[i] = x[i];
				for(int j=x[i-1]+1;j<x[i];j++) D.push_back(j);
			}
			else
			{
				z[i] = D.back();
				D.pop_back();
			}
		}
		
		for(int i=1;i<=a;i++) printf("%d ",y[i]);
		printf("\n");
		for(int i=1;i<=a;i++) printf("%d ",z[i]);
		printf("\n");
	}
}