#include <stdio.h>
int x[110];
int abs(int k)
{
	return k>0?k:-k;
}
int max(int a, int b, int c, int d)
{
	int m = abs(a);
	m = m > abs(b) ? m: abs(b);
	m = m > abs(c) ? m: abs(c);
	m = m > abs(d) ? m: abs(d);
	return m;
}
int main()
{
	int a,b,c;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]==1) b = i;
		if(x[i]==a) c = i;
	}
	int m1 = max(b-1,b-2,b-a,b-a+1);
	int m2 = max(c-1,c-2,c-a,c-a+1);
	printf("%d",max(m1,m2,c-b,0));
}