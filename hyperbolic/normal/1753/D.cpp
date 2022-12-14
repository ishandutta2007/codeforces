#include <stdio.h>
#include <queue>
#include <vector>
#define MAX (long long int)1e18

struct str{
	int first;
	int second;
	long long int dist;
};
bool operator<(str a, str b)
{
	return a.dist>b.dist;
}
std::priority_queue<str> Q;

std::vector< std::vector<char> > x;
std::vector< std::vector<long long int> > dist;
char y[300010];

int direX[1010]={1,0,-1,0},direY[1010]={0,1,0,-1};
int direX2[1010],direY2[1010];
int main()
{
	direX2['U'] = 1, direY2['U'] = 0;
	direX2['R'] = 0, direY2['R'] = -1;
	direX2['D'] = -1, direY2['D'] = 0;
	direX2['L'] = 0, direY2['L'] = 1;
	
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	x.resize(a+2);
	for(int i=0;i<=a+1;i++) x[i].resize(b+2);
	
	dist.resize(a+2);
	for(int i=0;i<=a+1;i++) dist[i].resize(b+2);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) dist[i][j] = MAX;
	
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		for(int j=1;j<=b;j++) x[i][j] = y[j];
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='.')
			{
				Q.push({i,j,0});
			}
		}
	}
	
	while(!Q.empty())
	{
		int s = Q.top().first;
		int t = Q.top().second;
		long long int D = Q.top().dist;
		Q.pop();
		if(dist[s][t]<=D) continue;
		dist[s][t] = D;
		
		for(int k=0;k<4;k++)
		{
			int s2 = s+direX[k];
			int t2 = t+direY[k];
			if(1<=s2&&s2<=a&&1<=t2&&t2<=b);
			else continue;
			
			int d1 = direX2[x[s2][t2]];
			int d2 = direY2[x[s2][t2]];
			if(d1==0 && d2==0) continue;
			if(k%2==0)
			{
				if(d2==0) Q.push({s2+d1,t2+d2,D+d});
				else Q.push({s2+d1,t2+d2,D+c});
			}
			else
			{
				if(d2==0) Q.push({s2+d1,t2+d2,D+c});
				else Q.push({s2+d1,t2+d2,D+d});
			}
		}
	}
	
	long long int ans = MAX;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=0;k<4;k++)
			{
				int s = i+direX[k];
				int t = j+direY[k];
				if(1<=s&&s<=a&&1<=t&&t<=b);
				else continue;
				long long int val = dist[i][j] + dist[s][t];
				ans = ans<val?ans:val;
			}
		}
	}
	if(ans>=MAX) printf("-1");
	else printf("%lld",ans);
}