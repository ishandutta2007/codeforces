#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
double l, v1, v2;
int cnt;

int main() {
	scanf("%d%lf%lf%lf%d", &n, &l, &v1, &v2, &k);
	cnt = (n + k - 1) / k;
	double t1 = 2 * l / (2 * v1 * (cnt - 1) + v1 + v2);
	double L = (v1 + v2) * t1 / 2;
	printf("%.12f\n", L / v2 + (l - L) / v1);
	return 0;
}