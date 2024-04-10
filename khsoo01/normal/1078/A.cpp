#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c, xs, ys, xe, ye;

double ans, x[4], y[4], v[4];

int main()
{
	scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&xs,&ys,&xe,&ye);
	ans = abs(xs - xe) + abs(ys - ye);
	if(a == 0 || b == 0) {
		printf("%.12f\n", ans);
		return 0;
	}
	x[0] = xs;
	y[0] = (double) (-c + -a*xs) / b;
	v[0] = abs(y[0] - ys);
	x[1] = (double) (-c + -b*ys) / a;
	y[1] = ys;
	v[1] = abs(x[1] - xs);
	x[2] = xe;
	y[2] = (double) (-c + -a*xe) / b;
	v[2] = abs(y[2] - ye);
	x[3] = (double) (-c + -b*ye) / a;
	y[3] = ye;
	v[3] = abs(x[3] - xe);
	for(int i=0;i<2;i++) {
		for(int j=2;j<4;j++) {
			ans = min(ans, hypot(x[i] - x[j], y[i] - y[j]) + v[i] + v[j]);
		}
	}
	printf("%.12f\n", ans);
}