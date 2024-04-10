#include <cstdio>
#include <cmath>

const double pi = acos(-1);

const int o = 524288;

int a[1111111];
double x[1111111], y[1111111];
int z[1111111];

int main()
{
	double tx, ty;
	int i, j, k, n, m, tz;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) a[i + o] = x[i + o] = 1;
	for (i = o - 1; i >= 0; i--) x[i] = x[i << 1] + x[i << 1 | 1];
	while (m--)
	{
		scanf("%d%d%d", &i, &j, &k);
		j += o - 1;
		if (i == 1) a[j] += k;
		else z[j] = (z[j] + k) % 360;
		x[j] = a[j] * cos(z[j] * pi / 180);
		y[j] = a[j] * -sin(z[j] * pi / 180);
		while (j >>= 1)
		{
			x[j] = x[j << 1] + x[j << 1 | 1] * cos(z[j << 1] * pi / 180) + y[j << 1 | 1] * sin(z[j << 1] * pi / 180);
			y[j] = y[j << 1] - x[j << 1 | 1] * sin(z[j << 1] * pi / 180) + y[j << 1 | 1] * cos(z[j << 1] * pi / 180);
			z[j] = (z[j << 1] + z[j << 1 | 1]) % 360;
		}
		printf("%.10f %.10f\n", x[1], y[1]);
	}
}