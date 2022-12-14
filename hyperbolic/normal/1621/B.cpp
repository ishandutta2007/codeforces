#include <stdio.h>
#define MAX 2000000001
int x[100010],y[100010],z[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int b,c,d,e;
		scanf("%d%d%d",&b,&c,&d);
		printf("%d\n",d);
		x[1] = b, y[1] = c, z[1] = d;
		e = 1;
		int min = 1, max = 1;
		for(int i=2;i<=a;i++)
		{
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			x[i] = b, y[i] = c, z[i] = d;
			
			int s1 = MAX, s2 = MAX, s3 = MAX;
			
			if(e!=-1 && x[e]<=b&&c<=y[e]) s1 = z[e];
			
			if(b<x[min]) e=-1,min = i;
			else if(b==x[min]&&d<z[min]) min = i;
			if(c>y[max]) e=-1,max = i;
			else if(c==y[max]&&d<z[max]) max = i;
			if(b==x[min]&&c==y[max])
			{
				if(e==-1) e = i;
				else if(z[e]>d) e = i;
				s2 = z[e];
			}
			s3 = z[min]+z[max];
			
			printf("%d\n",s1<s2?s3<s1?s3:s1:s3<s2?s3:s2);
		}
	}
}