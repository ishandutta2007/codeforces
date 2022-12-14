#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

int min1[1010][1010],min2[1010][1010],max1[1010][1010],max2[1010][1010];
int x[1010][1010];

std::priority_queue< std::pair<int,int> > Q;
std::priority_queue< std::pair<int,int> , std::vector< std::pair<int,int> > , std::greater< std::pair<int,int> > > Q2;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) Q.push(std::make_pair(x[i][j],j));
		int prev = -1;
		int count = 0, count2=0;
		while(!Q.empty())
		{
			int x0 = Q.top().first;
			int y0 = Q.top().second;
			Q.pop();
			
			if(x0==prev) min1[i][y0] = count;
			else
			{
				count++;
				min1[i][y0] = count;
			}
			prev = x0;
		}
		
		for(int j=1;j<=b;j++) Q2.push(std::make_pair(x[i][j],j));
		prev = -1;
		count = 0, count2=0;
		while(!Q2.empty())
		{
			int x0 = Q2.top().first;
			int y0 = Q2.top().second;
			Q2.pop();
			
			if(x0==prev) max1[i][y0] = count;
			else
			{
				count++;
				max1[i][y0] = count;
			}
			prev = x0;
		}
	}
	
	for(int j=1;j<=b;j++)
	{
		for(int i=1;i<=a;i++) Q.push(std::make_pair(x[i][j],i));
		int prev = -1;
		int count = 0, count2=0;
		while(!Q.empty())
		{
			int x0 = Q.top().first;
			int y0 = Q.top().second;
			Q.pop();
			
			if(x0==prev) min2[y0][j] = count;
			else
			{
				count++;
				min2[y0][j] = count;
			}
			prev = x0;
		}
		
		for(int i=1;i<=a;i++) Q2.push(std::make_pair(x[i][j],i));
		prev = -1;
		count = 0, count2=0;
		while(!Q2.empty())
		{
			int x0 = Q2.top().first;
			int y0 = Q2.top().second;
			Q2.pop();
			
			if(x0==prev) max2[y0][j] = count;
			else
			{
				count++;
				max2[y0][j] = count;
			}
			prev = x0;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int t1 = min1[i][j]>min2[i][j]?min1[i][j]:min2[i][j];
			int t2 = max1[i][j]>max2[i][j]?max1[i][j]:max2[i][j];
			printf("%d ",t1+t2-1);
		}
		printf("\n");
	}
}