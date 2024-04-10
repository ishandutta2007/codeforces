#include<stdio.h>
double a,b,c,d,s,x;
int main(void) {
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&c);
	scanf("%lf",&d);
	x=(1-a/b)*(1-c/d);
	s=(a/b)/(1-x);
	printf("%.9lf",s);
	return 0;
}