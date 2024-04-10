#include <stdio.h>
#include <algorithm>
int direX[5]={1,0,-1,0}, direY[5] = {0,1,0,-1};
int y[5] = {1,2,4,8}; // D R U L

std::pair<int,int> x[1010][1010];
int ans[1010][1010],check[1010][1010];
void func(int x1, int y1, int t1, int t2)
{
	for(int i=0;i<4;i++)
	{
		int x2 = x1 + direX[i];
		int y2 = y1 + direY[i];
		if(x[x2][y2]==std::make_pair(t1,t2) && ans[x2][y2] == 0)
		{
			ans[x2][y2] = y[(i+2)%4];
			func(x2,y2,t1,t2);
		}
		else check[x2][y2] += y[(i+2)%4];
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	if(a==1)
	{
		printf("INVALID");
		return 0;
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d%d",&x[i][j].first,&x[i][j].second);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(x[i][j].first==i&&x[i][j].second==j)
			{
				ans[i][j] = 16;
				func(i,j,i,j);
			}
		}
	}
	for(int j=1;j<=a;j++) check[1][j] += 4;
	for(int j=1;j<=a;j++) check[a][j] += 1;
	for(int i=1;i<=a;i++) check[i][1] += 8;
	for(int i=1;i<=a;i++) check[i][a] += 2;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(ans[i][j]==0 && x[i][j]!=std::make_pair(-1,-1))
			{
				printf("INVALID");
				return 0;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(ans[i][j]!=0) continue;
			
			if(check[i][j]==15)
			{
				printf("INVALID");
				return 0;
			}
			else
			{
				for(int k=1;k<=8;k*=2)
				{
					if((check[i][j]&k)==0)
					{
						ans[i][j] = k;
						break;
					}
				}
			}
		}
	}
	
	printf("VALID\n");
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(ans[i][j]==1) printf("D");
			else if(ans[i][j]==2) printf("R");
			else if(ans[i][j]==4) printf("U");
			else if(ans[i][j]==8) printf("L");
			else if(ans[i][j]==16) printf("X");
		}
		printf("\n");
	}
}