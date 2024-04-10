#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int query(int w) {
	printf("? %d\n", w);
	fflush(stdout);
	int h;
	scanf("%d", &h);
	return h;
}

void ans(int r) {
	printf("! %d\n", r);
	fflush(stdout);
}

int main()
{
	int n;
	scanf("%d", &n);

	int lo = 0;
	int hi = 5e6;
	while (hi - lo > 1) {
		int w = lo + (hi - lo) / 2;
		int h = query(w);
		if (h == 1) {
			hi = w;
		} else {
			lo = w;
		}
	}
	int w1 = hi;
	int ret = w1;
	for (int h = 2; h <= n; ++h) {
		for (int val = ret - 1; val > 0 && val >= w1 - n; --val) {
			if (val % h == 0) {
				int h2 = query(val / h);
				if (h2 == h) {
					ret = val;
				} else {
					break;
				}
			}
		}
	}
	ans(ret);
	return 0;
}