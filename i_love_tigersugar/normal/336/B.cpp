#include<cstdio>
#include<cmath>
typedef long long ll;
ll m;
int r;
double s;
void process(void) {
	scanf("%I64d",&m);
	scanf("%d",&r);
	ll i;
	s=0.0;
	double t;
	for (i=1;i<=m;i=i+1) {
		t=2.0*r;
		if (i>1) t+=(2+sqrt(2))*r;
		if (i<m) t+=(2+sqrt(2))*r;
		if (i>2) t+=(i-1)*(i-2)*r+(i-2)*2*sqrt(2)*r;
		if (i<m-1) t+=(m-i-1)*(m-i)*r+(m-i-1)*2*sqrt(2)*r;
		s+=t;
	}
	printf("%.9lf",s/(m*m));
}
int main(void) {
	process();
	return 0;
}