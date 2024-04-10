#include <stdio.h>
#include <string.h>
#include <queue>

struct str{
	int x0;
	int y0;
	int cost;
};
bool operator<(str a, str b)
{
	return a.cost>b.cost;
}
std::priority_queue<str> Q;

std::vector< std::pair<int,int> > V;

std::queue< std::pair<int,int> > Q2,Q3;
int a,b;
char x[2010][2010];
int check[2010][2010];

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	if(x[1][1]=='a') Q.push({1,1,0});
	else if(b>=1) Q.push({1,1,1});
	
	V.push_back(std::make_pair(1,1));
	int max = 2*a-2;
	while(!Q.empty())
	{
		int x0 = Q.top().x0;
		int y0 = Q.top().y0;
		int cost = Q.top().cost;
		Q.pop();
		if(check[x0][y0]) continue;
		check[x0][y0] = 1;
		if((a-x0)+(a-y0)<max)
		{
			max = (a-x0)+(a-y0);
			V.clear();
			V.push_back(std::make_pair(x0,y0));
		}
		else if((a-x0)+(a-y0)==max) V.push_back(std::make_pair(x0,y0));
		
		if(x0+1<=a)
		{
			if(check[x0+1][y0]==0)
			{
				if(x[x0+1][y0]=='a') Q.push({x0+1,y0,cost});
				else if(cost<b) Q.push({x0+1,y0,cost+1});
			}
		}
		if(y0+1<=a)
		{
			if(check[x0][y0+1]==0)
			{
				if(x[x0][y0+1]=='a') Q.push({x0,y0+1,cost});
				else if(cost<b) Q.push({x0,y0+1,cost+1});
			}
		}
	}
	
	if(b==0) printf("%c",x[1][1]);
	else printf("a");
	for(int i=3;i<=2*a-max;i++) printf("a");
	
	for(int i=0;i<V.size();i++) Q2.push(V[i]);
	for(int i=max-1;i>=0;i--)
	{
		char M = 'z'+1;
		while(!Q2.empty())
		{
			int x0 = Q2.front().first;
			int y0 = Q2.front().second;
			Q2.pop();
			if(check[x0][y0]==2) continue;
			check[x0][y0] = 2;
			
			if(x0+1<=a)
			{
				if(x[x0+1][y0]<M)
				{
					while(!Q3.empty()) Q3.pop();
					Q3.push(std::make_pair(x0+1,y0));
					M = x[x0+1][y0];
				}
				else if(x[x0+1][y0]==M) Q3.push(std::make_pair(x0+1,y0));
			}
			if(y0+1<=a)
			{
				if(x[x0][y0+1]<M)
				{
					while(!Q3.empty()) Q3.pop();
					Q3.push(std::make_pair(x0,y0+1));
					M = x[x0][y0+1];
				}
				else if(x[x0][y0+1]==M) Q3.push(std::make_pair(x0,y0+1));
			}
		}
		printf("%c",M);
		while(!Q3.empty()) Q2.push(Q3.front()),Q3.pop();
	}
}