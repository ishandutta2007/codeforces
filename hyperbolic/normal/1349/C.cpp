#include <stdio.h>
#include <queue>

struct str{
	int x0;
	int y0;
	int dist;
};
std::queue<str> Q;

int direX[5]={0,1,0,-1},direY[5]={1,0,-1,0};
char x[1010][1010];
int y[1010][1010],check[1010][1010],start[1010][1010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = x[i][j]-'0';
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) start[i][j] = -1;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(x[i][j]==x[i+direX[k]][j+direY[k]])
				{
					Q.push({i,j,0});
					break;
				}
			}
		}
	}
	
	
	while(!Q.empty())
	{
		int x0 = Q.front().x0;
		int y0 = Q.front().y0;
		int dist = Q.front().dist;
		Q.pop();
		if(1>x0 || x0>a) continue;
		if(1>y0 || y0>b) continue;
		
		if(check[x0][y0]) continue;
		check[x0][y0] = 1;
		start[x0][y0] = dist;
		
		for(int k=0;k<4;k++) Q.push({x0+direX[k],y0+direY[k],dist+1});
	}
	
	for(int i=1;i<=c;i++)
	{
		int d,e;
		long long int f;
		scanf("%d%d%lld",&d,&e,&f);
		if(start[d][e]==-1) printf("%d\n",y[d][e]);
		else if(f>=start[d][e]) printf("%d\n",(y[d][e] + (f-start[d][e])%2)%2);
		else printf("%d\n",y[d][e]);
	}
	
}