#include <bits/stdc++.h>
using namespace std;
double a[1000], b[1000], c[2000],w;
int n, m;
bool check(double f) {
	for (int i = 0; i < 2 * n; i++)f -= (f + w) / c[i];
	return f >= 0;
}
int main() {
	int i;
	scanf("%d%d", &n, &m);
	w = m;
	for (i = 0; i < n; i++)scanf("%lf", a + i);
	for (i = 0; i < n; i++)scanf("%lf", b + i);
	int co = 0;
	c[co++] = a[0];
	for (i = 1; i < n; i++) { c[co++] = b[i]; c[co++] = a[i]; }
	c[co] = b[0];
	double cur = 0;
	for (double d = 1e9; d >= 1e-9; d /= 2) {
		if (!check(cur + d))cur += d;
	}
	if (cur > 1e9)printf("-1");
	else printf("%lf", cur);
	getchar(); getchar();
}