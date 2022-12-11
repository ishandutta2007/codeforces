#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

const int N = 20050;
int n, a, b;
double p[N], q[N], k[N];

struct DP {
	int a, b; double f;
	DP(int A = 0, int B = 0, double F = 0) { f = F, a = A, b = B; }
}dp[N];

inline void Mx(DP &a, DP b) { a.f < b.f && (a = b, 0); }

inline DP com(DP a, DP b) {
	return DP(a.a + b.a, a.b + b.b, a.f + b.f);
}

void Check(double A, double B) {
	dp[0] = DP(); double C = A + B;
	for (int i = 1;i <= n; i++) {
		dp[i] = dp[i-1];
		Mx(dp[i], com(dp[i-1], DP(1, 0, p[i] - A)));
		Mx(dp[i], com(dp[i-1], DP(0, 1, q[i] - B)));
		Mx(dp[i], com(dp[i-1], DP(1, 1, k[i] - C)));
	}
}

double L, R;
void check(double A) {
	L = 0, R = 1;
	for (int i = 1;i <= 40; i++) {
		double mid = (L + R) / 2;
		Check(A, mid);
		if (dp[n].b >= b) L = mid;
		else R = mid;
	}
	Check(A, L);
}

const int T = 40;
int main() {
	read(n), read(a), read(b);
	for (int i = 1;i <= n; i++) scanf ("%lf", p + i);
	for (int i = 1;i <= n; i++) scanf ("%lf", q + i);
	for (int i = 1;i <= n; i++)
		k[i] = p[i] + q[i] - p[i] * q[i];
	double l = 0, r = 1;
	for (int i = 1;i <= T; i++) {
		double mid = (l + r) / 2;
		check(mid);
		if (dp[n].a >= a) l = mid;
		else r = mid;
	} check(l);
	printf ("%.5lf\n", dp[n].f + l * a + L * b);
	return 0;
}