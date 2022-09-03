#include<cstdio>
#include<cmath>
#include<algorithm>

double solve(long long p,long long q,long long r)
{
	if(q==0)return 1e9;
    if(p==0)
	{
		if(-(double)r/q>=0)return -(double)r/q;
		else return 1e9;
	}
    double t = (double)q*q-(double)4*p*r;
    double rr=1e9;
    if(t<0)return 1e9;
    t=sqrt(t);
    if((-q+t)/p/2>=0)rr=std::min(rr,(-q+t)/p/2);
    if((-q-t)/p/2>=0)rr=std::min(rr,(-q-t)/p/2);
    return rr;
}

int main()
{
	double t;
    long long a,b,c,d;
    int i,j,k,l;
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
    if(a*d==b*c)puts("0.000000000000");
    else
	{
		t=2e9;
		for(i=-1;i<=1;i+=2)for(j=-1;j<=1;j+=2)for(k=-1;k<=1;k+=2)for(l=-1;l<=1;l+=2)t=std::min(t,solve(i*l-j*k,-i*a+j*b+k*c-l*d,a*d-b*c));
		printf("%.12lf",t);
	}
}