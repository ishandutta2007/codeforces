#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

const int MAXN = 1005;

int n, r;
double x[MAXN], y[MAXN];

int main () {
	cin >> n >> r;
	for (int i=0; i<n; i++) {
		cin >> x[i];
		y[i]=r;
		for (int j=0; j<i; j++) {
			double d=abs(x[i]-x[j]);
			if (2*r>=d) y[i]=max(y[i], y[j]+sqrt(4*r*r-d*d));
		}
	}
	for (int i=0; i<n; i++) {
		printf("%.10f ", y[i]);
	}
	return 0;
}