#include <stdio.h>

struct str{
	int left;
	int top;
	int right;
	int bottom;
	int index;
}x[100010];

int sum[100010];
int value[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d,e,f,g;
		scanf("%d%d%d%d",&d,&e,&f,&g);
		if(d>f)
		{
			int t = d;
			d = f;
			f = t;
		}
		if(e>g)
		{
			int t = e;
			e = g;
			g = t;
		}
		x[i]={d,e,f,g,i};
	}
	int countL,countR,countT,countB;
	scanf("%d%d%d%d",&countL,&countR,&countT,&countB);
	
	for(int i=1;i<=100000;i++) sum[i] = 0;
	for(int i=1;i<=a;i++) sum[x[i].left]++;
	for(int i=1;i<=b;i++) sum[i] += sum[i-1];
	for(int i=1;i<=a;i++) if(sum[x[i].right-1]-(x[i].left<x[i].right?1:0)==countL) value[x[i].index]++;
	for(int i=1;i<=100000;i++) sum[i] = 0;
	for(int i=1;i<=a;i++) sum[x[i].right]++;
	for(int i=b;i>=1;i--) sum[i] += sum[i+1];
	for(int i=1;i<=a;i++) if(sum[x[i].left+1]-(x[i].left<x[i].right?1:0)==countR) value[x[i].index]++;
	for(int i=1;i<=100000;i++) sum[i] = 0;
	for(int i=1;i<=a;i++) sum[x[i].top]++;
	for(int i=1;i<=c;i++) sum[i] += sum[i-1];
	for(int i=1;i<=a;i++) if(sum[x[i].bottom-1]-(x[i].top<x[i].bottom?1:0)==countT) value[x[i].index]++;
	for(int i=1;i<=100000;i++) sum[i] = 0;
	for(int i=1;i<=a;i++) sum[x[i].bottom]++;
	for(int i=c;i>=1;i--) sum[i] += sum[i+1];
	for(int i=1;i<=a;i++) if(sum[x[i].top+1]-(x[i].top<x[i].bottom?1:0)==countB) value[x[i].index]++;
	
	for(int i=1;i<=a;i++)
	{
		if(value[i]==4)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
}