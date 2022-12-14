#include <stdio.h>

int x[110],y[110],s[110],t[110];
int ans[110][110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	for(int i=0;i<=30;i++)
	{
		for(int j=1;j<=a;j++) s[j] = x[j]%2;
		for(int k=1;k<=b;k++) t[k] = y[k]%2;
		
		int sum1 = 0, sum2 = 0;
		for(int j=1;j<=a;j++) sum1 += s[j];
		for(int k=1;k<=b;k++) sum2 += t[k];
		if((sum1+sum2)%2==1)
		{
			printf("NO");
			return 0;
		}
		if(sum1>sum2) t[1] += (sum1-sum2);
		else s[1] += (sum2-sum1);
		
		int p1 = 1, p2 = 1;
		while(1)
		{
			if(p1>a) break;
			if(p2>b) break;
			
			if(s[p1]==0) p1++;
			else if(t[p2]==0) p2++;
			else
			{
				ans[p1][p2] ^= (1<<i);
				s[p1]--, t[p2]--;
			}
		}
		for(int j=1;j<=a;j++) x[j]/=2;
		for(int j=1;j<=b;j++) y[j]/=2;
	}
	printf("YES\n");
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
}