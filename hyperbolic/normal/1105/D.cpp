#include <stdio.h>
#include <queue>
#include <vector>

int y[20];
long long int limit[20];
char x[1010][1010];
int ans[20];
struct str{
	int first;
	int second;
	int value;
};
std::queue<str> Q[20];
int direX[5]={1,0,-1,0},direY[5] = {0,1,0,-1};

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++) scanf("%d",&y[i]);
	
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if('0'<=x[i][j]&&x[i][j]<='9')
			{
				for(int k=0;k<4;k++) Q[x[i][j]-'0'].push({i+direX[k],j+direY[k],1});
			}
		}
	}
	
	while(1)
	{
		int control = 0;
		for(int i=1;i<=c;i++) if(Q[i].empty()) control++;
		if(control==c) break;
		
		for(int i=1;i<=c;i++)
		{
			limit[i] += y[i];
			while(!Q[i].empty())
			{
				int s = Q[i].front().first;
				int t = Q[i].front().second;
				int k = Q[i].front().value;
				if(k>limit[i]) break;
				
				Q[i].pop();
				if(x[s][t]!='.') continue;
				x[s][t] = '0'+i;
				
				for(int j=0;j<4;j++)
				{
					int s0 = s+direX[j];
					int t0 = t+direY[j];
					Q[i].push({s0,t0,k+1});
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if('0'<=x[i][j]&&x[i][j]<='9') ans[x[i][j]-'0']++;
	for(int i=1;i<=c;i++) printf("%d ",ans[i]);
}