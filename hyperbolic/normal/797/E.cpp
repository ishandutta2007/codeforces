#include <stdio.h>
#define SIZE 300

int a;
int x[100010];
int check[100010][301];
int func(int s, int t)
{
	if(s>a) return 0;
	if(check[s][t]) return check[s][t];
	else return check[s][t] = 1 + func(s+x[s]+t,t);
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(d>=SIZE)
		{
			int p = c;
			int count = 0;
			while(p<=a)
			{
				p = p + x[p] + d;
				count++;
			}
			printf("%d\n",count);
		}
		else printf("%d\n",func(c,d));
	}
}