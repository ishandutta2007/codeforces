#include <stdio.h>


int check[1010][10],b;
void func(int s,int t, int color)
{
	if(check[s][t]) return;
	check[s][t] = color;
	if(t>b) return;
	
	int c = (1<<(b-t));
	func(s,t+1,color);
	if((s&c)!=0) func(s-c,t+1,color);
}

int x[300010][10],y[300010][10];
int z[300010];
int main()
{
	int a;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	int C=0;
	for(int i=1;i<=b;i++) C*=2,C++;
	
	int min = 0, max = 1000000000;
	int ans1 = 1, ans2 = 1;
	while(min<=max)
	{
		int h = (min+max)/2;
		for(int i=0;i<=C;i++) for(int j=1;j<=b+1;j++) check[i][j] = 0;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]>=h) y[i][j] = 1;
				else y[i][j] = 0;
			}
		}
		for(int i=1;i<=a;i++)
		{
			int s = 0;
			for(int j=1;j<=b;j++) s*=2, s+=y[i][j];
			z[i] = s;
		}
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b+1;j++)
			{
				if(check[C-z[i]][j]!=0)
				{
					ans1 = check[C-z[i]][j];
					ans2 = i;
					min = h+1;
					goto u;
				}
			}
			func(z[i],1,i);
		}
		max = h-1;
		u:;
	}
	printf("%d %d",ans1,ans2);
}