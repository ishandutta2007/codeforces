#include <stdio.h>

int x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		
		int count1=0, count2=0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++) if(x[i][j]==1) goto u;
			count1++;
			u:;
		}
		for(int j=1;j<=b;j++)
		{
			for(int i=1;i<=a;i++) if(x[i][j]==1) goto v;
			count2++;
			v:;
		}
		int C = count1<count2?count1:count2;
		printf("%s\n",C%2==0?"Vivek":"Ashish");
	}
}