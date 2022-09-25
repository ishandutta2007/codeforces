#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

#define double long double

const int maxn=100100;
const double eps=1e-10;


int n;
int a,b,m,vx,vy,vz;
double step=-4*(1e-7);

double mn(double a, double b) {
	if (b-a>eps) return a;
	else return b;
}

double abs1(double x) {
	if (x<-eps) return -x;
	else return x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> a >> b >> m >> vx >> vy >> vz;
	double x=a/2.0, y=m, z=0;
	while (y>eps) {
		double t=1e9;
		t=mn(t,-y/vy);
		if (vx<0) 
			t=mn(t,-x/vx);
		else
			t=mn(t,(a-x)/vx);
		if (vz<0) 
			t=mn(t,-z/vz);
		else
			t=mn(t,(b-z)/vz);
		x+=vx*t;
		y+=vy*t;
		z+=vz*t;
		if (vx<0) {
			if (abs1(-x/vx-t)<eps) vx=-vx;
		} else {
			if (abs1((a-x)/vx-t)<eps) vx=-vx; 
		}
		if (vz<0) {
			if (abs1(-z/vz-t)<eps) vz=-vz;
		} else {
			if (abs1((b-z)/vz-t)<eps) vz=-vz; 
		}
		/*y+=step;
		x+=step/vy*vx;
		z+=step/vy*vz;
		if (x<eps) vx=-vx;
		if (x>a+eps) vx=-vx;
		if (z<eps) vz=-vz;
		if (z>b+eps) vz=-vz;*/
	}
	printf("%.08lf %.08lf",x,z);
	return 0;
}