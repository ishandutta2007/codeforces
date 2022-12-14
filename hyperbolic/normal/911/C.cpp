#include <stdio.h>

int x[5],y[5];
int check[100010];
int main()
{
	for(int i=1;i<=3;i++) scanf("%d",&x[i]);
	
	for(y[1]=0;y[1]<=4;y[1]++)
	{
		for(y[2]=0;y[2]<=4;y[2]++)
		{
			for(y[3]=0;y[3]<=4;y[3]++)
			{
				int start = y[1];
				start = start>y[2]?start:y[2];
				start = start>y[3]?start:y[3];
				
				for(int j=start;j<=start+1000;j++) check[j] = 0;
				for(int i=y[1];i<=start+1000;i+=x[1]) if(i>=start) check[i] =1;
				for(int i=y[2];i<=start+1000;i+=x[2]) if(i>=start) check[i] =1;
				for(int i=y[3];i<=start+1000;i+=x[3]) if(i>=start) check[i] =1;
				for(int j=start;j<=start+1000;j++) if(check[j]==0) goto u;
				printf("YES");
				return 0;
				u:;
			}
		}
	}
	
	printf("NO");
}