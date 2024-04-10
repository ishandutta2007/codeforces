#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

int main() {
	int a = input(), b = input();
	int x = input(), y = input();
	int n = input();

	if(x > y) {
		std::swap(x, y);
		std::swap(a, b);
	}

	int min = 0, max = 0;
	int m = n;
	int A = a, B = b;
	while(m)
		if(A) {
			if(m >= x) {
				m -= x;
				max ++;
				A --;
			} else
				break;
		} else if(B) {
			if(m >= y) {
				m -= y;
				max ++;
				B --;
			} else
				break;
		} else
			break;

	while(n)
		if(b) {
			if(n >= y - 1) {
				n -= y - 1;
				b --;
			} else
				break;
		} else if(a) {
			if(n >= x - 1) {
				n -= x - 1;
				a --;
			} else
				break;
		} else {
			min = n;
			break;
		}

	printf("%d %d\n", min, max);
}