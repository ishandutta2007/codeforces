#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double best = 1e50;

double aps(double x) {
	return x < 0 ? -x : x;
}

int main() {
	int n;
	double a, b, x, y, c;

	scanf("%lf%lf%d", &x, &y, &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf%lf", &a, &b, &c);
		best = min(best, sqrt((a - x)*(a - x) + (b - y)*(b - y)) / c);

	}

	printf("%.14lf\n", best);



	return 0;
}