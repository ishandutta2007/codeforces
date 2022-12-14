#include <stdio.h>

int check[510][510];
int count[510];

int getQuery(int k, int a)
{
	printf("? ");
	for(int i=1;i<=a;i++) if(check[i][k]==1) printf("%d ",i);
	printf("\n");
	fflush(stdout);
	
	int c;
	scanf("%d",&c);
	return c;
}

int start;
int func(int k, int C, int d)
{
	for(int i=start;i<start+d;i++)
	{
		int j = (i-1)%d+1;
		if(count[j]>=1 && C>=1)
		{
			check[k][j] = 1;
			count[j]--, C--;
		}
		else check[k][j] = 0;
	}
	
	if(C>0) return 0;
	else return 1;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int d=1;d<=500;d++)
	{
		if((d*b-a+1000)%2==1) continue;
		
		int ans = 0;
		int C = d*b;
		for(int j=1;j<=d;j++) count[j] = b;
		start = 1;
		for(int i=1;i<=a;i++)
		{
			int sum = 0;
			for(int j=1;j<=d;j++) if(count[j]>0) sum++;
			int M = ((sum-1)/2)*2+1;
			
			if((C-M)>=(a-i))
			{
				int s = func(i,M,d);
				if(s==0) goto u;
				start = (start+M-1)%d+1;
				C -= M;
			}
			else
			{
				int h = (C-a+i);
				int s = func(i,h,d);
				if(s==0) goto u;
				start = (start+h-1)%d+1;
				C -= h;
			}
		}
		
		if(C>0) continue;
		
		for(int j=1;j<=d;j++)
		{
			int t = getQuery(j,a);
			ans ^= t;
		}
		printf("! %d",ans);
		fflush(stdout);
		return 0;
		
		u:;
	}
	printf("-1");
	fflush(stdout);
}