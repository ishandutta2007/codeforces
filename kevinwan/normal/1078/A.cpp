#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double py(double a, double b) {
	return sqrt(a*a + b * b);
}
int main() {
	double a, b, c;
	double x1, y1, x2, y2;
	scanf("%lf%lf%lf", &a, &b, &c);
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	double ans = abs(x1-x2)+abs(y1-y2);
	if (a&&b) {
		double h1 = -((a*x1 + b * y1 + c) / a);
		double h2 = -((a*x2 + b * y2 + c) / a);
		double v1 = -((a*x1 + b * y1 + c) / b);
		double v2 = -((a*x2 + b * y2 + c) / b);
		ans = min(ans, abs(h1) + py((x1 + h1) - (x2 + h2), y2 - y1) + abs(h2));
		ans = min(ans, abs(h1) + py((x1 + h1) - (x2 ), (y2+v2) - y1) + abs(v2));
		ans = min(ans, abs(v1) + py((x1) - (x2 + h2), y2 - (y1+v1)) + abs(h2));
		ans = min(ans, abs(v1) + py((x1) - (x2), (y2+v2) - (y1+v1)) + abs(v2));
	}
	printf("%lf", ans);
	getchar(); getchar();
}