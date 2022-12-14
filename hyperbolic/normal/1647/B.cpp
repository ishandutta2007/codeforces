#include <stdio.h>

char x[110][110];
int y[110][110],check[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i][j] = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[i][j] = 0;
		for(int i=1;i<=a+2;i++) for(int j=1;j<=b+2;j++) y[i][j] = 0;
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i+1][j+1] = x[i][j]-'0';
		for(int i=1;i<=a+2;i++) for(int j=1;j<=b+2;j++) y[i][j] += y[i][j-1];
		for(int j=1;j<=b+2;j++) for(int i=1;i<=a+2;i++) y[i][j] += y[i-1][j];
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j] -= '0';
		for(int i=0;i<=a+1;i++) x[i][b+1] = 0;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]==1&&check[i][j]==0)
				{
					int s = i, t = j;
					while(s<=a&&x[s][j]==1) s++;
					s--;
					while(t<=b&&x[i][t]==1) t++;
					t--;
					
					if(y[s+1][t+1] - y[i-1+1][t+1] - y[s+1][j-1+1] + y[i-1+1][j-1+1]!=(s-i+1)*(t-j+1))
					{
						printf("NO\n");
						goto u;
					}
					if(y[s+1+1][t+1+1] - y[i-2+1][t+1+1] - y[s+1+1][j-2+1] + y[i-2+1][j-2+1] - x[i-1][j-1] - x[i-1][t+1] - x[s+1][j-1] - x[s+1][t+1] != (s-i+1)*(t-j+1))
					{
						printf("NO\n");
						goto u;
					}
					
					for(int k=i;k<=s;k++) for(int l=j;l<=t;l++) check[k][l] = 1;
				}
			}
		}
		printf("YES\n");
		u:;
	}
}