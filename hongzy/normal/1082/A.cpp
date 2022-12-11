#include <cstdio>

int ab(int x) { return x > 0 ? x : -x;  }
int min(int x, int y) { return x < y ? x : y; }

int main() {
	int T; scanf("%d", &T);
	for(; T --; ) {
		int n, a, b, d, ans;
		scanf("%d%d%d%d", &n, &a, &b, &d);
		if(a == b) ans = 0;
		else if(ab(b - a) % d == 0) ans = ab(b - a) / d;
		else {
			ans = 1 << 30; //(a - 1) / d = k
			if((b - 1) % d == 0) ans = min(ans, (b - 1) / d + (a - 1 + d - 1) / d);
			if((n - b) % d == 0) ans = min(ans, (n - b) / d + (n - a + d - 1) / d);
			if(ans == 1 << 30) ans = -1;
		}
		printf("%d\n", ans);
	}
	return 0;
}