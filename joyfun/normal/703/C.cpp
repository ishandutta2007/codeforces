#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

int dcmp(double x) {
	if (fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

int n;
double w, u, v;
int main() {
	while (~scanf("%d%lf%lf%lf", &n, &w, &v, &u)) {
		double x, y;
		double Max = 0, Min = 1e18;
		while (n--) {
			scanf("%lf%lf", &x, &y);
			double xx = x - y / u * v;
			Max = max(Max, xx);
			Min = min(Min, xx);
		}
		double ans = 0;
		if (dcmp(Min) >= 0) ans = w / u;
		else ans = Max / v + w / u;
		printf("%.12lf\n", ans);
	}
	return 0;
}