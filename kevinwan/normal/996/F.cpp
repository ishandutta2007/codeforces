#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double d[1 << 18];
int main() {
	int n, r,i,a;
	double b;
	double tot=0;
	scanf("%d%d", &n, &r);
	for (i = 0; i < 1 << n; i++)scanf("%lf", d + i), tot += d[i];
	printf("%lf\n", tot / (1 << n));
	for (i = 0; i < r; i++) {
		scanf("%d%lf", &a, &b);
		tot += b - d[a];
		d[a] = b;
		printf("%lf\n", tot/(1<<n));
	}
	getchar(); getchar();
}