#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const double pi = std::acos(-1);

const int mxn = 105;

int n;
double x[mxn], y[mxn];

int main() {
	scanf("%d", &n);
	if (n == 3 || n == 4) {
		printf("No solution\n");
		return 0;
	}
	double cx = 0, cy = 0;
	for (int i = 0; i < n; ++ i) {
		x[i] = cx;
		y[i] = cy;
		double len = 500 + 0.01 * i;
		double dx = std::cos(2.0 * pi / n * i);
		double dy = std::sin(2.0 * pi / n * i);
		if (i == n - 1) {
			cx += -cy / dy * dx;
			cy = 0;
			x[0] = cx;
			y[0] = cy;
			break;
		}
		cx += len * dx;
		cy += len * dy;
	}
	rep(i, n) printf("%.6f %.6f\n", x[i], y[i]);
#ifdef DEBUG
	eprintf("polygon(");
	rep(i, n) {
		if (i) eprintf(", ");
		eprintf("(%.6f, %.6f)", x[i], y[i]);
	}
	eprintf(")\n");
#endif
	return 0;
}