#include <stdio.h>

int direX[10]={1,1,1,0,-1,-1,-1,0}, direY[10]={1,0,-1,-1,-1,0,1,1};
char x[1010][1010];
int a,b;
int check[1010][1010];
int func(int i, int j)
{
	if(check[i][j]) return 0;
	check[i][j] = 1;
	int ans = 1;
	for(int k=0;k<8;k++)
	{
		int s = i+direX[k];
		int t = j+direY[k];
		if(1<=s&&s<=a&&1<=t&&t<=b&&x[s][t]=='*') ans += func(s,t);
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[i][j] = 0;
		
		int control = 1;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='*')
				{
					int C = 0;
					for(int k=0;k<8;k++)
					{
						int s = i+direX[k];
						int t = j+direY[k];
						if(1<=s&&s<=a&&1<=t&&t<=b&&x[s][t]=='*') C++;
					}
					if(C!=2) control = 0;
				}
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='*'&&check[i][j]==0)
				{
					if(func(i,j)!=3) control = 0;
				}
			}
		}
		
		if(control) printf("YES\n");
		else printf("NO\n");
	}
}