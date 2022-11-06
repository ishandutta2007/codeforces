#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

typedef long long llong;

int n;
int a, b;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &b);
		llong ll = a; ll *= b;
		llong s = 1, e = 1000000;
		while (s < e) {
			llong m = (s + e) / 2;
			llong mm = m * m * m;
			if (mm == ll) {
				s = m; break;
			}
			else if (mm < ll) {
				s = m + 1;
			}
			else {
				e = m - 1;
			}
		}
		if (s * s * s != ll && a % s != 0 || b % s != 0) {
			printf("No\n");
			continue;
		}
		a /= s; b /= s;
		if (a * b == s) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}