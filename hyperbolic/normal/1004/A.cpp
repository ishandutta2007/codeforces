#include <stdio.h>

int a,b;
int x[110];
int abs(int k)
{
	return k>0?k:-k;
}
int func(int k)
{
	int dist = abs(k-x[1]);
	for(int i=2;i<=a;i++) dist = dist<abs(k-x[i])?dist:abs(k-x[i]);
	if(dist==b) return 1;
	else return 0;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		count += func(x[i]-b);
		count += func(x[i]+b);
	}
	for(int i=1;i<a;i++) if(x[i+1]-x[i]==2*b) count -= func(x[i]+b);
	printf("%d",count);
}