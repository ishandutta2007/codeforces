#include <iostream>
#include <cstdio>
using namespace std;

int n;
double p[100010], ans;
double f[100010], g[100010];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%lf", &p[i]);
	f[0] = 0;
	for(int i=1; i<=n; i++) {
		ans += p[i] * (2 * f[i-1] + 1);
		f[i] = (f[i-1] + 1) * p[i];
	}
	printf("%.15f\n", ans);
	return 0;
}