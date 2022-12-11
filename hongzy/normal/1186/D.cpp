#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N], ans[N];
double x[N];

int main() {
	scanf("%d", &n);
	int l1 = 0, l2 = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%lf", &x[i]);
		a[i] = (int) x[i];
//		if(x[i] == a[i]) b[i] = a[i];
//		else b[i] = (x[i] > 0 ? a[i] + 1 : a[i] - 1);
		if(x[i] > 0) {
			l1 += a[i];
		} else if(x[i] < 0) {
			l2 += - a[i];
		}
	}
	int l = max(l1, l2);
	int d1 = l - l1, d2 = l - l2;
	for(int i = 1; i <= n; i ++) {
		int ans = a[i];
		if(x[i] > 0) {
			if(x[i] != a[i] && (-- d1 >= 0)) {
				ans ++;
			}
		} else if(x[i] < 0) {
			if(x[i] != a[i] && (-- d2 >= 0)) {
				ans --;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}