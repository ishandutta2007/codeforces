#include <stdio.h>
#include <math.h>

double dist(double x1, double y1, double z1, double x2, double y2, double z2)
{
     return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

int main()
{
     int n, vp, vs, px, py, pz, i;
     int x[10001], y[10001], z[10001];
     double t[10001], c[10001][3];
     double l, r, m, xs, ys, zs;

     scanf("%d", &n);

     for (i = 0; i <= n; i++) scanf("%d %d %d", &x[i], &y[i], &z[i]);

     scanf("%d %d", &vp, &vs);
     scanf("%d %d %d", &px, &py, &pz);

     if (x[0] == px && y[0] == py && z[0] == pz) {
	  puts("YES");
	  puts("0");
	  printf("%d %d %d\n", px, py, pz);

	  return 0;
     }

     t[0] = 0;

     for (i = 1; i <= n; i++) {
	  double d = dist(x[i], y[i], z[i], x[i - 1], y[i - 1], z[i - 1]);

	  t[i] = t[i - 1] + d / vs;
	  c[i][0] = (x[i] - x[i - 1]) * vs / d;
	  c[i][1] = (y[i] - y[i - 1]) * vs / d;
	  c[i][2] = (z[i] - z[i - 1]) * vs / d;
     }

     if (dist(x[n], y[n], z[n], px, py, pz) / vp > t[n] + 1e-6) {
	  puts("NO");

	  return 0;
     }

     xs = x[n], ys = y[n], zs = z[n];

     l = 0, r = t[n], m = (l + r) / 2;

     while (r - l > 1e-10) {
	  int lb = -1, rb = n + 1, mb = (lb + rb) / 2;

	  while (rb - lb > 1) {
	       if (t[mb] >= m) {
		    rb = mb;
		    mb = (lb + rb) / 2;
	       } else {
		    lb = mb;
		    mb = (lb + rb) / 2;
	       }
	  }

	  if (rb == n + 1) {
	       r = m;
	       m = (l + r) / 2;
	  } else {
	       double xn, yn, zn;

	       xn = x[rb - 1] + c[rb][0] * (m - t[rb - 1]);
	       yn = y[rb - 1] + c[rb][1] * (m - t[rb - 1]);
	       zn = z[rb - 1] + c[rb][2] * (m - t[rb - 1]);

	       if (dist(xn, yn, zn, px, py, pz) / vp <= m) {
		    r = m;
		    m = (l + r) / 2;

		    xs = xn; ys = yn; zs = zn;
	       } else {
		    l = m;
		    m = (l + r) / 2;
	       }
	  }
     }

     puts("YES");
     printf("%.9lf\n", r);
     printf("%.9lf %.9lf %.9lf\n", xs, ys, zs);

     return 0;
}