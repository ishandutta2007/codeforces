#include<bits/stdc++.h>
using namespace std;
const double eps=1e-4;
double a,b,c,s,r,A,B,t,pi;
double x[5],y[5];
double fgcd(double a,double b){
	return fabs(b)<eps?fabs(a):fgcd(b,fmod(a,b));
}
int main(){
	for(int i=1;i<=3;++i){
		scanf("%lf%lf",x+i,y+i);
	}
	a=sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
	b=sqrt((x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]));
	c=sqrt((x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1]));
	s=0.5*fabs(x[1]*y[2]+x[2]*y[3]+x[3]*y[1]-x[1]*y[3]-x[2]*y[1]-x[3]*y[2]);
	r=0.25*a*b*c/s;
	A=asin(2*s/(b*c));
	B=asin(2*s/(c*a));
	pi=atan2(0,-1);
	t=fgcd(pi,fgcd(A,B));
	printf("%lf",0.5*pi*r*r*sin(t*2)/t);
	return 0;
}