#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;

const int MAXN = 100010;

int n, arr_a[MAXN], arr_b[MAXN];
LL x[MAXN], y[MAXN];

double Rand01() {
	return rand() / (double) RAND_MAX;
}

double calc(int *a) {
	LL px = 0, py = 0;
	for(int i=1; i<=n; i++) {
		px += x[i] * a[i];
		py += y[i] * a[i];
	}
	return sqrt(px*px + py*py);
}

void Change(int times, int *a, int *b) {
	for(int i=1; i<=n; i++) b[i] = a[i];
	for(int i=1; i<=times; i++)
		b[rand() % n + 1] *= -1;
}

int main() {
	srand(21854397);
//	freopen("data.in", "r", stdin);
//	freopen("G_out.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%lld%lld", &x[i], &y[i]);

	int * a = arr_a, * b = arr_b;
	for(int i=1; i<=n; i++) a[i] = 1;
	double ans = calc(a);
	double T = n * 10, T_end = 1e-4, d = 0.90;
	while(T > T_end) {
		for(int i=0; i<3; i++) {
			if(ans <= 1.5 * 1e6) {
				for(int i=1; i<=n; i++)
					printf("%d%c", a[i], " \n"[i == n]);
				return 0;
			}
			if((int)(T * 0.3) == 0) break;
			Change(T * 0.3, a, b);
			double now_ans = calc(a), next_ans = calc(b);
			double delta = next_ans - now_ans;
			if(delta < 0 || Rand01() < exp(- delta / T)) {
				swap(a, b);
				if(next_ans < ans) ans = next_ans;
			}
		}
		T *= d;
	}
	
	LL px = 0, py = 0;
	LL x1, y1, x2, y2, s1, s2;
	for(int i=1; i<=n; i++) {
		x1 = px + x[i], y1 = py + y[i];
		x2 = px - x[i], y2 = py - y[i];
		s1 = x1*x1 + y1*y1;
		s2 = x2*x2 + y2*y2;
		if(s1 < s2) px = x1, py = y1, a[i] = 1;
		else px = x2, py = y2, a[i] = -1;
	}
	for(int i=1; i<=n; i++)
		printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}