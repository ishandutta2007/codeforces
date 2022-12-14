#include <stdio.h>
#include <vector>

char x[1000010];
int y[1000010];
int check1[1000010],check2[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=a*b;i++) y[i] = x[i]-'0';
		for(int i=1;i<=a*b;i++) y[i] += y[i-1];
		
		int ans = 0;
		int C = 1;
		for(int j=0;j<=b;j++) check1[j] = 0;
		for(int j=1;j<=b;j++) check2[j] = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(C<=b) check1[C] = check1[C-1];
				if(x[C]=='1')
				{
					if(check2[j]==0)
					{
						check2[j] = 1;
						ans++;
					}
					if(C<=b) check1[C] = 1;
				}
				if(C>b) check1[(C-1)%b+1] += (y[C]-y[C-b]>0?1:0);
				printf("%d ",ans+check1[(C-1)%b+1]);
				C++;
			}
		}
		printf("\n");
	}
}