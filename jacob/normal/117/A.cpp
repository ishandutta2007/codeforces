#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;

int nextMoment(int t, int f) {
	int pos = t % (2*m - 2);
	int r1 = f - 1;
	int r2 = 2*m - 2 - (f - 1);
	if (r1 < pos) r1 += 2*m - 2;
	if (r2 < pos) r2 += 2*m - 2;
	return min(r1, r2) - pos + t;
}

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int s, f, t;
		scanf("%d%d%d", &s, &f, &t);
		if (s == f) printf("%d\n", t); else
		printf("%d\n", nextMoment(nextMoment(t, s), f));
	}
	return 0;
}