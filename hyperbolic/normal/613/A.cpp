#include <stdio.h>
#include <math.h>
struct str{
	int x0;
	int y0;
}x[100010];
double dist(str a, str b)
{
	long long int s1 = ((long long int)(a.x0-b.x0)) *(a.x0-b.x0);
	long long int s2 = ((long long int)(a.y0-b.y0)) *(a.y0-b.y0);
	return sqrt(s1+s2);
} 
double func(str a, str b, str c)
{
	// a^2 = b^2+c^2 -2bccosA
	// cosA = b^2+c^2-a^2 ~~~
	if(dist(a,b)*dist(a,b)+dist(b,c)*dist(b,c)-dist(a,c)*dist(a,c)<0)
	{
		return dist(a,b)<dist(a,c)?dist(a,b):dist(a,c);
	}
	else if(dist(a,c)*dist(a,c)+dist(b,c)*dist(b,c)-dist(a,b)*dist(a,b)<0)
	{
		return dist(a,b)<dist(a,c)?dist(a,b):dist(a,c);
	}
	else
	{
		long long int s1 = (long long int)a.x0 * b.y0 + (long long int)b.x0 * c.y0 + (long long int)c.x0 * a.y0;
		long long int s2 = (long long int)a.y0 * b.x0 + (long long int)b.y0 * c.x0 + (long long int)c.y0 * a.x0;
		long long int s = s1-s2>0? s1-s2:s2-s1;
		return s / dist(b,c);
	}
}
int main()
{
	int a,b,c,i;
	double max,min;
	scanf("%d%d%d",&a,&b,&c);
	x[0] = {b,c};
	for(i=1;i<=a;i++)
	{
		scanf("%d%d",&x[i].x0,&x[i].y0);
	}
	x[a+1] = x[1];
	min = func(x[0],x[1],x[2]);
	for(i=2;i<=a;i++)
	{
		min = min<func(x[0],x[i],x[i+1])?min:func(x[0],x[i],x[i+1]);
	}
	max = dist(x[0],x[1]);
	for(i=2;i<=a;i++)
	{
		max = max>dist(x[0],x[i])?max:dist(x[0],x[i]);
	}
	printf("%.20lf",M_PI *(max*max - min*min));
}