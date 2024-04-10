#include <stdio.h>
#include <algorithm>
#define MAX 12345
int x[110],y[110];
int main()
{
	int a,b,c,i,s=1,t=1;
	scanf("%d",&a);
	scanf("%d",&b);
	for(i=1;i<=b;i++) scanf("%d",&x[i]);
	scanf("%d",&c);
	for(i=1;i<=c;i++) scanf("%d",&y[i]);
	std::sort(x+1,x+b+1);
	std::sort(y+1,y+c+1);
	x[b+1]=y[c+1]=MAX;
	for(i=1;i<=a;i++)
	{
		while(1)
		{
			if(x[s]==i) break;
			else if(y[t]==i) break;
			else if(x[s]<i) s++;
			else if(y[t]<i) t++;
			else
			{
				printf("Oh, my keyboard!");
				return 0;
			}
		}
	}
	printf("I become the guy.");
}