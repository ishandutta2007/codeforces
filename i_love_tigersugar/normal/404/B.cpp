#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
typedef long long ll;
double a,d;
int n;
ll fls(double x) {
	ll t=floor(x);
	FOR(i,-3,3) if (t+i>x) return (t+i-1);
	assert(false);
}
int main(void) {
	scanf("%lf%lf%d",&a,&d,&n);
	FOR(i,1,n) {
		ll tmp=fls(i*d/a);
		double rest=i*d-tmp*a;		
		if (tmp%4==0) printf("%.9lf %.9lf\n",rest,0.0);
		if (tmp%4==1) printf("%.9lf %.9lf\n",a,rest);
		if (tmp%4==2) printf("%.9lf %.9lf\n",a-rest,a);
		if (tmp%4==3) printf("%.9lf %.9lf\n",0.0,a-rest);
	}
	return 0;
}