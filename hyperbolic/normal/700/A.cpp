#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	int n;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	n = (a-1)/e+1;
	
	double r = (double)(n-1) /(c+d)*(2*d);
	// A = rB, cA+dB = L => (cr+d)B = L
	double B = (double)b/(c*r+d);
	double A = r * B;
	printf("%.12lf",A+B);
}