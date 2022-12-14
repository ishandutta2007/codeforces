#include <stdio.h>

int direX[5]={1,0,-1,0},direY[5]={0,1,0,-1};

char x[110][110];
int check[110][110];
int a,b;
int func(int s, int t)
{
	if(x[s][t]=='#') return 0;
	if(s<1 || s>a) return 0;
	if(t<1 || t>b) return 0;
	if(check[s][t]) return 0;
	check[s][t] = 1;
	
	int S = 0;
	if(x[s][t]=='G') S++;
	for(int i=0;i<4;i++) S += func(s+direX[i],t+direY[i]);
	return S;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int count = 0;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i][j] = '#';
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) check[i][j] = 0;
		
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='B')
				{
					for(int k=0;k<4;k++)
					{
						int s = i+direX[k];
						int t = j+direY[k];
						if(x[s][t]=='G')
						{
							printf("No\n");
							goto u;
						}
						if(x[s][t]=='.') x[s][t] = '#';
					}
				}
			}
		}
		
		count = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='G') count++;
		
		if(func(a,b)==count) printf("Yes\n");
		else printf("No\n");
		u:;
	}
}